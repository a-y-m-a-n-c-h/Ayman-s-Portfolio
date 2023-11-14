from flask import Blueprint,render_template,request,flash,redirect,url_for
from .Models import users
from werkzeug.security import generate_password_hash, check_password_hash
from .import db
from flask_login import login_user, login_required, logout_user,current_user
import smtplib
import random

auth=Blueprint('auth',__name__) 

@auth.route('/sign-up',methods=["POST", "GET"])
def signUp():
    if request.method=='POST':
        first_name=request.form.get('firstName')
        last_name=request.form.get('lastName')
        email=request.form.get('email')
        password1=request.form.get('password1')
        password2=request.form.get('password2')

        user=users.query.filter_by(email=email).first()
        if user:
            flash('Email already exists.', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        elif len(email)<4:
            flash('Email must be greater than 3 characters!', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        elif len(first_name)<2:
            flash('First Name must be greater than 1 character!', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        elif len(last_name)<2:
            flash('Last Name must be greater than 1 character!', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        elif password1!=password2:
            flash('Passwords do not match', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        elif len(password1)<7:
            flash('Password must be at least 7 characters!', category='error')
            return render_template("signUp.html",user=current_user,email=email,first_name=first_name,last_name=last_name)
        else:
            new_user=users(email=email,firstName=first_name,lastName=last_name,password=generate_password_hash(password=password1,method='sha256'))
            db.session.add(new_user) 
            db.session.commit()
            login_user(new_user,remember=True)
            flash('Account created!', category='success')
            return redirect(url_for('auth.user'))

    return render_template("signUp.html",user=current_user)
 
@auth.route('/login', methods=["POST", "GET"]) 
def login():
    if request.method =="POST":
        email=request.form.get('email')
        password=request.form.get('password')

        user=users.query.filter_by(email=email).first()
        if user:
            if check_password_hash(user.password,password): #user.password==password: 
                flash('Logged in successfully!',category='success')
                login_user(user,remember=True) #it is the remember me
                return redirect(url_for('views.home'))
            else:
                flash('Incorrect password, try again.', category='error')
        else:
            flash('Email does not exist.',category='error')
    return render_template("login.html",user=current_user)


@auth.route('/user',methods=["POST", "GET"])
@login_required
def user():
    if request.method=='POST':
        age=request.form.get('age')
        nationality=request.form.get('nationality')
        phoneNum=request.form.get('phoneNum')
        adress=request.form.get('adress')

        if len(age)==0 or int(age)<16:
            flash('You are underage, you cannot proceed with this application', category='error')
        elif len(phoneNum)<10: #assuming the phone number is lebanese
            flash('Please enter a valid phone number', category='error')
        else:
            user=users.query.filter_by(email=current_user.email).first()
            user.age=int(age)
            user.nationality=nationality
            user.phoneNum=phoneNum
            user.adress=adress
            db.session.commit()
            flash('Saved Successfully!', category='success')
            return render_template("profile.html",user=current_user)
        return render_template("user.html",user=current_user,age=age,nationality=nationality,phoneNum=phoneNum,adress=adress)
    else:
        return render_template("user.html",user=current_user,age=current_user.age,nationality=current_user.nationality,phoneNum=current_user.phoneNum,adress=current_user.adress)


@auth.route('/request',methods=["GET","POST"])
def request_change():
    if request.method=="POST":
        email=request.form.get('email')
        user=users.query.filter_by(email=email).first()
        if user:
            flash('An email was sent to you, please confirm to proceed.', category='success')
            code=random.randint(1000,5000)
            message="You have requested to reset your password. Kindly confirm your email adress by entering the following code "+str(code)
            server=smtplib.SMTP("smtp.gmail.com",587)
            server.starttls()
            server.login("chalambassy.hotel@gmail.com","ybseoldwizcxzyjs")
            server.sendmail("chalambassy.hotel@gmail.com",email,message)
            return redirect(url_for('auth.code',code=code,email=email))
        else: 
            flash('Email not found, please register first.', category='error')
    return render_template("request.html")

@auth.route('/request_code/<code>/<email>',methods=["GET","POST"])
def code(code,email):
    if request.method=="POST":
        code_form=request.form.get('code')
        if code==code_form:
            flash('Acount Verified.', category='success')
            return redirect(url_for('auth.change_pass',email=email))
        else:
            flash('Invalid Code, please try again', category='error')  
            return render_template("code.html",email=email) 
    else:
        return render_template("code.html",email=email)

@auth.route('/change_pass/<email>',methods=["GET","POST"])
def change_pass(email):
    if request.method=="POST":
        password1=request.form.get('password1')
        password2=request.form.get('password2')
        if password1!=password2:
            flash('Passwords do not match', category='error')
            return render_template("change_pass.html")
        elif len(password1)<7:
            flash('Password must be at least 7 characters!', category='error')
            return render_template("change_pass.html")
        else:
            user=users.query.filter_by(email=email).first()
            user.password=generate_password_hash(password1, method='sha256')
            db.session.commit()
            flash('Saved Successfully!', category='success')
            return redirect(url_for('auth.login'))
    else:
        return render_template("change_pass.html")


@auth.route('/profile',methods=["POST", "GET"])
@login_required
def profile():
    return render_template("profile.html",user=current_user)
   

@auth.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect("login")

