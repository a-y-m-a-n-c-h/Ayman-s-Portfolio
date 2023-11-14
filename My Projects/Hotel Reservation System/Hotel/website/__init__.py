from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager
from flask_mysqldb import MySQL
import mysql.connector
from itsdangerous import URLSafeTimedSerializer

db=SQLAlchemy()
s=URLSafeTimedSerializer('blabla')

#create the object of Flask
def create_app():
    app = Flask(__name__)
    app.secret_key="blabla"
    app.config["SQLALCHEMY_DATABASE_URI"] = "mysql+mysqlconnector://root:Yasmeen12@localhost/hotel"
    app.config["SQLALCHEMY_TRACK_MODIFICATIONS"]=False

    db.init_app(app)  

    from .auth import auth
    from .views import views
    app.register_blueprint(views,url_prefix='/')
    app.register_blueprint(auth,url_prefix='/')

    from .Models import users
    with app.app_context():
        db.create_all()   

    login_manager=LoginManager()
    login_manager.login_view='auth.login'
    login_manager.init_app(app)

    @login_manager.user_loader
    def load_user(id):
        return users.query.get(int(id))
        
    return app