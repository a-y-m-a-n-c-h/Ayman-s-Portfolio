from .import db
from flask_login import UserMixin
from sqlalchemy.sql import func
import intervaltree
class users(db.Model,UserMixin):
    id=db.Column("id",db.Integer,primary_key=True)
    firstName=db.Column("firstName",db.String(60))
    lastName=db.Column("lastName",db.String(60))
    email=db.Column("email",db.String(100),unique=True)
    password=db.Column("password",db.String(60))
    age=db.Column("age",db.Integer)
    nationality=db.Column("nationality",db.String(50))
    phoneNum=db.Column("phone number",db.String(20))
    adress=db.Column("adress",db.String(200))
    booked_rooms=db.relationship('reservedRooms',backref='booked')

    def __init__(self,firstName,lastName,email,password):
        self.firstName=firstName
        self.lastName=lastName
        self.email=email
        self.password=password

class roomss(db.Model):
    number=db.Column("number",db.Integer,primary_key=True) #i assumed the id to be the room number
    type=db.Column("type",db.String(60))
    capacity=db.Column("capacity",db.Integer)
    price=db.Column("price",db.Integer)
    seaView=db.Column("seaview",db.Boolean)
    poolView=db.Column("poolview",db.Boolean)
    reservedTimes = intervaltree.IntervalTree()

    def __init__(self,type,capacity,price,seaView,poolView):
        self.type=type
        self.capacity=capacity
        self.price=price
        self.seaView=seaView
        self.poolView=poolView

class reservedRooms(db.Model):
    id=db.Column("id",db.Integer,primary_key=True)
    number=db.Column("number",db.Integer)
    type=db.Column("type",db.String(60))
    price=db.Column("price",db.Integer)
    seaView=db.Column("seaView",db.Boolean)
    poolView=db.Column("poolView",db.Boolean)
    extraBed=db.Column("extra bed",db.Boolean)
    breakfast=db.Column("breakfast",db.Boolean)
    start_date=db.Column("start date",db.Date())
    end_date=db.Column("end date",db.Date())
    user_id=db.Column("user_id",db.Integer,db.ForeignKey('users.id'))
    review=db.Column("review",db.String(600))
    

    def __init__(self,number,type,price,seaView,poolView,extraBed,breakfast,start,end):
        self.number=number
        self.type=type
        self.price=price
        self.seaView=seaView
        self.poolView=poolView
        self.extraBed=extraBed
        self.breakfast=breakfast
        self.start_date=start
        self.end_date=end


