################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 6.3.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QMainWindow, QMenu,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(170, 60, 561, 131))
        self.votes_Button = QPushButton(self.centralwidget)
        self.votes_Button.setObjectName(u"votes_Button")
        self.votes_Button.setGeometry(QRect(290, 300, 151, 41))
        self.admin_Button = QPushButton(self.centralwidget)
        self.admin_Button.setObjectName(u"admin_Button")
        self.admin_Button.setGeometry(QRect(290, 370, 151, 41))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 800, 21))
#        self.menue_vote = QMenu(self.menubar)
#        self.menue_vote.setObjectName(u"menue_vote")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

#        self.menubar.addAction(self.menue_vote.menuAction())

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"<html><head/><body><p><span style=\" font-size:72pt;\">e-Pays  </span><span style=\" font-size:14pt;\">Powered with BlockChain</span></p></body></html>", None))
        self.votes_Button.setText(QCoreApplication.translate("MainWindow", u"Registrar transaccion", None))
        self.admin_Button.setText(QCoreApplication.translate("MainWindow", u"Ingresar como administrador", None))
#        self.menue_vote.setTitle(QCoreApplication.translate("MainWindow", u"e-vote", None))
    # retranslateUi

