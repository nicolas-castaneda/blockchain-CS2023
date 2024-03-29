################################################################################
## Form generated from reading UI file 'votos.ui'
##
## Created by: Qt User Interface Compiler version 6.3.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QComboBox, QDialog, QLabel,
    QLineEdit, QPushButton, QSizePolicy, QVBoxLayout,
    QWidget)

class Ui_Votes(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(656, 350)
        self.label = QLabel(Dialog)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(20, 50, 91, 31))
        self.label_2 = QLabel(Dialog)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(20, 100, 91, 31))
        self.label_3 = QLabel(Dialog)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(20, 140, 91, 31))
        self.lineEdit_1 = QLineEdit(Dialog)
        self.lineEdit_1.setObjectName(u"lineEdit_2")
        self.lineEdit_1.setGeometry(QRect(130, 150, 131, 21))
        self.lineEdit_2 = QLineEdit(Dialog)
        self.lineEdit_2.setObjectName(u"lineEdit_2")
        self.lineEdit_2.setGeometry(QRect(130, 100, 131, 21))
        self.lineEdit_3 = QLineEdit(Dialog)
        self.lineEdit_3.setObjectName(u"lineEdit_3")
        self.lineEdit_3.setGeometry(QRect(130, 60, 131, 21))
        self.add_Button = QPushButton(Dialog)
        self.add_Button.setObjectName(u"add_Button")
        self.add_Button.setGeometry(QRect(310, 60, 101, 51))
        self.verticalLayoutWidget = QWidget(Dialog)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(20, 240, 581, 361))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)

        self.home_Button = QPushButton(Dialog)
        self.home_Button.setObjectName(u"home_Button")
        self.home_Button.setGeometry(QRect(580, 20, 51, 51))

        self.label_error = QLabel(Dialog)
        self.label_error.setObjectName(u"label_error")
        self.label_error.setGeometry(QRect(120, 200, 181, 21))

        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.label.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p align=\"right\"><span style=\" font-size:14pt;\">Remitente:</span></p></body></html>", None))
        self.label_2.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p align=\"right\"><span style=\" font-size:14pt;\">Receptor:</span></p></body></html>", None))
        self.label_3.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p align=\"right\"><span style=\" font-size:14pt;\">Monto:</span></p></body></html>", None))

        self.add_Button.setText(QCoreApplication.translate("Dialog", u"REGISTRAR", None))
        self.home_Button.setText(QCoreApplication.translate("Dialog", u"HOME", None))
        self.label_error.setText(QCoreApplication.translate("Dialog", u"POR FAVOR LLENE TODOS LOS DATOS", None))
        self.label_error.hide()
    # retranslateUi
