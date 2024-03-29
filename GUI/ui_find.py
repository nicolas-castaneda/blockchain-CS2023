################################################################################
## Form generated from reading UI file 'find.ui'
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

class Ui_Find(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(738, 487)
        self.comboBox = QComboBox(Dialog)
        self.comboBox.activated.connect(self.showInputs)
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.setObjectName(u"comboBox")
        self.comboBox.setGeometry(QRect(40, 100, 151, 31))
        self.verticalLayoutWidget = QWidget(Dialog)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(390, 90, 301, 241))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.label_2 = QLabel(Dialog)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(390, 60, 281, 31))
        self.label_3 = QLabel(Dialog)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(40, 60, 131, 21))
        self.pushButton = QPushButton(Dialog)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(220, 100, 75, 23))
        self.reset_Button = QPushButton(Dialog)
        self.reset_Button.setObjectName(u"reset_Button")
        self.reset_Button.setGeometry(QRect(390, 350, 101, 21))
        self.reset_Button.clicked.connect(lambda checked: self.clearLayout(self.verticalLayout))
        self.verticalLayoutWidget_2 = QWidget(Dialog)
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2")
        self.verticalLayoutWidget_2.setGeometry(QRect(20, 150, 241, 131))
        self.verticalLayout_2 = QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.label_4 = QLabel(self.verticalLayoutWidget_2)
        self.label_4.setObjectName(u"label_4")

        self.verticalLayout_2.addWidget(self.label_4)

        self.lineEdit = QLineEdit(self.verticalLayoutWidget_2)
        self.lineEdit.setObjectName(u"lineEdit")

        self.verticalLayout_2.addWidget(self.lineEdit)
        self.lbl = QLabel("Y: ")
        self.line = QLineEdit()
        self.verticalLayout_2.addWidget(self.lbl)
        self.verticalLayout_2.addWidget(self.line)

        self.label_error = QLabel(Dialog)
        self.label_error.setObjectName(u"label_error")
        self.label_error.setGeometry(QRect(50, 410, 181, 41))

        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.comboBox.setItemText(0, QCoreApplication.translate("Dialog", u"Igual a X", None))
        self.comboBox.setItemText(1, QCoreApplication.translate("Dialog", u"Entre X y Y", None))
        self.comboBox.setItemText(2, QCoreApplication.translate("Dialog", u"Inicia Con ...", None))
        self.comboBox.setItemText(3, QCoreApplication.translate("Dialog", u"Est\u00e1 Contenido en ...", None))
        self.comboBox.setItemText(4, QCoreApplication.translate("Dialog", u"M\u00e1ximo valor de ...", None))
        self.comboBox.setItemText(5, QCoreApplication.translate("Dialog", u"M\u00ednimo valor de ...", None))

        self.label_2.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p><span style=\" font-size:14pt;\">Resultados:</span></p></body></html>", None))
        self.label_3.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p><span style=\" font-size:14pt;\">Buscar:</span></p></body></html>", None))
        self.pushButton.setText(QCoreApplication.translate("Dialog", u"Buscar", None))
        self.reset_Button.setText(QCoreApplication.translate("Dialog", u"Reset", None))
        self.label_4.setText(QCoreApplication.translate("Dialog", u"Valor de X: ", None))
        self.label_error.setText(QCoreApplication.translate("Dialog", u"POR FAVOR LLENE TODOS LOS DATOS", None))
        self.label_error.hide()
        self.lbl.hide()
        self.line.hide()
    
    def addElements(self, res):
        # Read elements from res
        for i in res:
            temp = QLabel(i)
            self.verticalLayout.addWidget(temp)
    
    def showInputs(self):
        if self.comboBox.currentIndex() == 0:
            self.label_4.setText("Valor de X: ")
            self.lineEdit.show()
            self.lbl.hide()
            self.line.setText("")
            self.line.hide()
        elif self.comboBox.currentIndex() == 1:
            self.lineEdit.show()
            self.line.show()
            self.lbl.show()
            self.label_4.setText("X: ")            
        elif self.comboBox.currentIndex() == 2:
            self.label_4.setText("Inicia con: ")
            self.lineEdit.show()
            self.line.hide()
            self.line.setText("")
            self.lbl.hide()
        elif self.comboBox.currentIndex() == 3:
            self.label_4.setText("Contiene: ")
            self.lineEdit.show()
            self.line.hide()
            self.line.setText("")
            self.lbl.hide()
        elif self.comboBox.currentIndex() == 4:
            self.label_4.setText("M\u00e1ximo valor del BlockChain ")
            self.lineEdit.hide()
            self.line.setText(" ")
            self.lineEdit.setText(" ")
            self.line.hide()
            self.lbl.hide()
        elif self.comboBox.currentIndex() == 5:
            self.label_4.setText("M\u00ednimo valor del BlockChain ")
            self.lineEdit.hide()
            self.lineEdit.setText(" ")
            self.line.setText(" ")
            self.line.hide()
            self.lbl.hide()
        else:
            self.lineEdit.hide()
    
    def clearLayout(self, layout):
        while layout.count():
            child = layout.takeAt(0)
            if child.widget():
                child.widget().deleteLater()