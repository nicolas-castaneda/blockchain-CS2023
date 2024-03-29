# Socket connection to the server
import socket
# This Python file uses the following encoding: utf-8
import sys
import time
# from PySide6.QtWidgets import QApplication, uic
from PySide6.QtWidgets import QApplication, QMainWindow
from ui_mainwindow import Ui_MainWindow
from ui_votes import Ui_Votes
from ui_admin import Ui_Admin
from ui_find import Ui_Find
from ui_modify import Ui_Modify

msg = "[Jose,Rocio,500,FECHA],[Jose,Carlos,150,FECHA],[Jose,Maria,620,FECHA]"
def read(msg):
    r = []
    temp = ""
    for i in msg:
        if i == "]":
            r.append(temp)
            temp = ""
        elif i == ",":
            temp +=" "
        elif i != "[":
            temp += i
    return r
res = read(msg)
'''# How many bytes server will read at once
HEADER = 64
# Connecting to this PORT
PORT = 5050
FORMAT = "utf-8"
# Message to disconnect from the server
DISCONNECT_MESSAGE = "DISCONNECTED"
# Server IP
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
# Result of the query
# Creating a socket & Client global variable
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)
# How to send a message to the server
def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)
    # Result of the query ---- IMPORTANT
    res = read(client.recv(2048).encode(FORMAT))'''



class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        # Main window
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        # Main Window buttons to open other windows
        self.ui.votes_Button.clicked.connect(self.votes)
        self.ui.admin_Button.clicked.connect(self.admin)

        # Windows buttons to send messages to the server
        # self.votes.vote_Button.clicked.connect(lambda checked: send("NEW_VOTE, " + self.votes.label_7.text()))
        # self.find_.comboBox.currentText()

    def votes(self):
        self.window = QMainWindow()
        self.ui_v = Ui_Votes()
        self.ui_v.setupUi(self.window)
        self.show_window(self.window, self)
        self.ui_v.home_Button.clicked.connect(lambda checked: self.show_window(self, self.window))
        self.ui_v.add_Button.clicked.connect(self.addTransaction)

    def admin(self):
        self.window = QMainWindow()
        self.ui_a = Ui_Admin()
        self.ui_a.setupUi(self.window)
        self.show_window(self.window, self)
        self.ui_a.home_Button.clicked.connect(lambda checked: self.show_window(self, self.window))
        self.ui_a.load_Button.clicked.connect(self.load)
        self.ui_a.find_Button.clicked.connect(self.find_)
        self.ui_a.modify_Button.clicked.connect(self.modify)

    def find_(self):
        self.window1 = QMainWindow()
        self.ui_f = Ui_Find()
        self.ui_f.setupUi(self.window1)
        self.show_window(self.window1, self)
        self.ui_f.pushButton.clicked.connect(self.search)

    def modify(self):
        self.window1 = QMainWindow()
        self.ui_m = Ui_Modify()
        self.ui_m.setupUi(self.window1)
        self.show_window(self.window1, self)
        self.ui_m.pushButton.clicked.connect(self.modify_)

    # win1 = window to show | win2 = window to hide
    def show_window(self, win1, win2):
        if win1.isVisible():
            win1.hide()
            win2.show()
        else:
            win2.hide()
            win1.show()
    def search(self):
        if self.ui_f.lineEdit.text() != "":
            self.ui_f.label_error.hide()
            #send("SEARCH, " + self.ui_f.comboBox.currentText() + ", " + self.ui_f.lineEdit.text())
            print(self.ui_f.comboBox.currentText() + ", " + self.ui_f.lineEdit.text() +", " +self.ui_f.line.text() )
            self.ui_f.addElements(res)
        else:
            self.ui_f.label_error.show()
        
    def addTransaction(self):
        if (self.ui_v.lineEdit_3.text() != "" and self.ui_v.lineEdit_2.text() != "" and self.ui_v.lineEdit_1.text() != ""):
            self.ui_v.label_error.hide()
            msg="INSERT, " + self.ui_v.lineEdit_3.text() + ", " + self.ui_v.lineEdit_2.text()+", " + self.ui_v.lineEdit_1.text() + ", " + "FECHA"
            #send("INSERT, " + self.ui_v.lineEdit_3.text() + ", " + self.ui_v.lineEdit_2.text()", " + self.ui_v.lineEdit_1.text() + ", " + "FECHA")
            #send(msg)
            print(msg)
        else:
            self.ui_v.label_error.show()
    
    def load(self):
        #send("LOAD")
        print("LOAD")
        #self.ui_a.label.setText("Numero de Bloques: " + "\n"+ res[0])
        self.ui_a.label.setText("Numero de Bloques: " +" \n5")
        #self.ui_a.label_2.setText(res[1])
        #self.ui_a.label_3.setText(res[2])
        self.ui_a.label_loaded.setText("Data Cargada Correctamente")
        self.ui_a.load_Button.setEnabled(False)

    def modify_(self):
        if (self.ui_m.lineEdit_3.text() != "" and self.ui_m.lineEdit_2.text() != "" and self.ui_m.lineEdit.text() != "" and self.ui_m.lineEdit_4.text() != ""):
            self.ui_m.clearLayout(self.ui_m.verticalLayout)
            self.ui_m.label_3.setText("Modificacion Exitosa")
            #send("MODIFY, " + self.ui_m.lineEdit.text() + ", " + self.ui_m.lineEdit_2.text() + ", " + self.ui_m.lineEdit_3.text() + ", " self.ui_m.lineEdit_4.text() + ", " + "FECHA")
            print("MODIFY, " + self.ui_m.lineEdit.text() + ", " + self.ui_m.lineEdit_2.text() + ", " + self.ui_m.lineEdit_3.text() + ", "+ self.ui_m.lineEdit_4.text() + ", " + "FECHA")
            self.ui_m.addData(res)
        else:
            self.ui_m.label_3.setText("INGRESAR DATOS CORRECTAMENTE")


if __name__ == "__main__":
    # Creating the app
    app = QApplication(sys.argv)
    w = MainWindow()
    w.show()
    app.exec_()
    sys.exit(app.exec())

