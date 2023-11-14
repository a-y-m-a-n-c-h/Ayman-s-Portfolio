from flask import Blueprint,render_template,request,flash,redirect,url_for
from flask_login import  login_required, current_user
from . import db
import datetime
from datetime import datetime
from .Models import roomss, reservedRooms
from .import s
import smtplib
from itsdangerous import SignatureExpired
from intervaltree import Interval

views=Blueprint('views',__name__)


@views.route('/')
def home():
    return render_template('index.html')

@views.route('/rooms')
@login_required
def rooms():
    return render_template('rooms.html')

@views.route('/about')
@login_required
def about():
    return render_template('about.html')

@views.route('/facilities')
@login_required
def facilities():
    return render_template('facilities.html')

@views.route('/reservation/<type>/<start>/<end>/<roomNumber>/<price>',methods=["GET","POST"])
@login_required
def reservation(type,start,end,roomNumber,price):
    start=datetime.date(datetime.strptime(start, "%Y-%m-%d"))
    end=datetime.date(datetime.strptime(end, "%Y-%m-%d"))
    x=end-start
    price=(int(x.days)*(int(price)))
    if request.method=="POST":
        email=current_user.email 
        token=s.dumps(email)
        link=url_for('views.confirm_reserve',token=token, type=type,start=start,end=end,roomNumber=roomNumber,price=price,external=True)
        message="Welcome to Chalambassy Hotel, to confirm your reservation kindly press of the following link {}".format(link)
        server=smtplib.SMTP("smtp.gmail.com",587)
        server.starttls()
        server.login("chalambassy.hotel@gmail.com","ybseoldwizcxzyjs")
        server.sendmail("chalambassy.hotel@gmail.com",email,message)
        flash('A confirmation has been sent to your email', category='success')
        return render_template('reservation.html')
    else:
        return render_template('reservation.html',user=current_user,type=type,start=start,end=end,price=price)

@views.route('/confirm_reserve/<token>/<type>/<start>/<end>/<roomNumber>/<price>')
def confirm_reserve(token,type,start,end,roomNumber,price):
    try:
        email=s.loads(token,max_age=3600)
    except SignatureExpired:
        return flash('Your token has expired.',category='error') 
    room = roomss.query.filter_by(number=roomNumber).first()
    start=datetime.date(datetime.strptime(start, "%Y-%m-%d"))
    end=datetime.date(datetime.strptime(end, "%Y-%m-%d"))
    dateIntegerStart = start.year*10000 + start.month*100 + start.day
    dateIntegerEnd = end.year*10000 + end.month*100 + end.day
    room.reservedTimes.addi(dateIntegerStart,dateIntegerEnd)
    reservedRoom = reservedRooms(roomNumber,type,price,1,0,1,1,start,end)
    reservedRoom.user_id= current_user.id
    db.session.add(reservedRoom)
    db.session.commit()
    flash('Your room is now reserved! Feel free to explore our other rooms and book more!', category='success')
    return redirect(url_for('views.rooms'))

@views.route('/singleroom',methods=["GET","POST"])
@login_required
def single_room(): 
    if request.method=="POST":
        s=request.form.get('from')
        e=request.form.get('to')
        price=request.form.get('totalValue')
        if s=="" or e=="" or s==None or e==None:
            flash('Please enter the desired dates',category='error')
            return  render_template("singleroom.html")
        else:
            start=datetime.date(datetime.strptime(s, "%Y-%m-%d"))
            end=datetime.date(datetime.strptime(e, "%Y-%m-%d"))
            dateIntegerStart = start.year*10000 + start.month*100 + start.day
            dateIntegerEnd = end.year*10000 + end.month*100 + end.day
            if(dateIntegerEnd<dateIntegerStart):
                flash('StartDate is bigger than end date', category='error')
                return render_template('singleroom.html') 
            userDate = Interval(dateIntegerStart,dateIntegerEnd)
            roomList=roomss.query.filter_by(type="Single room").all()
            for room in roomList:
                if room.reservedTimes.overlaps_range(userDate.begin,userDate.end):
                    continue
                else:
                    return redirect(url_for('views.reservation',type="Single Room",start=start,end=end,roomNumber=room.number,price=price))
            flash('Sorry, this room is not available', category='error')
            return render_template('singleroom.html')   
            
    else:
        return render_template('singleroom.html',user=current_user)

@views.route('/doubleroom')
@login_required
def double_room():
    return render_template('doubleroom.html')

@views.route('/deluxeroom')
@login_required
def deluxe_room():
    return render_template('deluxeroom.html')

@views.route('/familyroom')
@login_required
def family_room():
    return render_template('familyroom.html')
 
@views.route('/royalroom')
@login_required
def royal_room():
    return render_template('royalroom.html')

@views.route('/queenroom')
@login_required
def queen_room():
    return render_template('queenroom.html')


@views.route('/mybooking')
@login_required
def my_booking():
    return render_template('mybooking.html',user=current_user)

@views.route('/delete-reservation/<id>', methods=["GET"])
def delete_reservation(id):
    Rroom = reservedRooms.query.get(id)
    RoominT = roomss.query.filter_by(number = Rroom.number).first()
    start = Rroom.start_date
    end = Rroom.end_date
    start = start.year*10000 + start.month*100 + start.day
    end = end.year*10000 + end.month*100 + end.day
    RoominT.reservedTimes.discardi(start,end)
    db.session.delete(Rroom)
    db.session.commit()
    return render_template('mybooking.html')

@views.route('/edit-reservation/<id>',methods=["GET","POST"])
@login_required
def edit_reservation(id):
    Rroom = reservedRooms.query.get(id)
    if Rroom.breakfast==1:
        a="Yes"
    else:
        a="No"
    if Rroom.extraBed==1:
        b="Yes"
    else:
        b="No"
    if request.method=="POST":
        breakfast_new=request.form.get('breakfast')
        bed_new=request.form.get('bed')
        s="Yes"
        if Rroom.breakfast==1:
            if breakfast_new.casefold()==s.casefold(): #it means he want to remove breakfast
                Rroom.breakfast=0
                Rroom.price-=25
                db.session.commit()
        else:
            if breakfast_new.casefold()==s.casefold(): #it means he want to add breakfast
                Rroom.breakfast=1
                Rroom.price+=25
                db.session.commit()
        if Rroom.extraBed==1:
            if bed_new.casefold()==s.casefold(): #he wants to remove bed
                Rroom.extraBed=0
                Rroom.price-=10
                db.session.commit()
        else:
            Rroom.extraBed=1 #he wants to add bed
            Rroom.price+=10
            db.session.commit()          
        return redirect(url_for('views.my_booking'))
    else:
        return render_template('editpage.html',breakfast=a,bed=b,user=current_user)

@views.route('/reviews/<id>',methods=["GET","POST"])
@login_required
def reviews(id):
    if request.method=="POST":
        room = reservedRooms.query.get(id)
        review=request.form.get('review')
        room.review=review
        db.session.commit()
        return redirect(url_for('views.my_booking'))
    else:
        return render_template('review.html',user=current_user)

