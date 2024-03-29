## Form generated from reading UI file 'modify.ui' 
 
## 
 
## Created by: Qt User Interface Compiler version 6.4.1 
 
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
 
from PySide6.QtWidgets import (QApplication, QDialog, QLabel, QLineEdit, 
 
    QPushButton, QSizePolicy, QVBoxLayout, QWidget) 
 
 
 
class Ui_Modify(object): 
 
    def setupUi(self, Dialog): 
        if not Dialog.objectName(): 
            Dialog.setObjectName(u"Dialog") 
        Dialog.resize(755, 472) 
        self.verticalLayoutWidget = QWidget(Dialog) 
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget") 
        self.verticalLayoutWidget.setGeometry(QRect(360, 80, 361, 281)) 
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget) 
        self.verticalLayout.setObjectName(u"verticalLayout") 
        self.verticalLayout.setContentsMargins(0, 0, 0, 0) 
        self.verticalLayoutWidget_2 = QWidget(Dialog) 
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2") 
        self.verticalLayoutWidget_2.setGeometry(QRect(30, 140, 271, 221)) 
        self.verticalLayout_2 = QVBoxLayout(self.verticalLayoutWidget_2) 
        self.verticalLayout_2.setObjectName(u"verticalLayout_2") 
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0) 
 
        self.label = QLabel(self.verticalLayoutWidget_2) 
        self.label.setObjectName(u"label") 
        self.verticalLayout_2.addWidget(self.label) 

        self.lineEdit = QLineEdit(self.verticalLayoutWidget_2) 
        self.lineEdit.setObjectName(u"lineEdit") 

        self.verticalLayout_2.addWidget(self.lineEdit) 
 
        self.label_2 = QLabel(self.verticalLayoutWidget_2) 
        self.label_2.setObjectName(u"label_2") 
        self.verticalLayout_2.addWidget(self.label_2) 
 
        self.lineEdit_2 = QLineEdit(self.verticalLayoutWidget_2) 
        self.lineEdit_2.setObjectName(u"lineEdit_2") 
        self.verticalLayout_2.addWidget(self.lineEdit_2) 
        self.label_5 = QLabel(self.verticalLayoutWidget_2) 
        self.label_5.setObjectName(u"label_5") 
 
        self.verticalLayout_2.addWidget(self.label_5) 
        self.lineEdit_3 = QLineEdit(self.verticalLayoutWidget_2) 
        self.lineEdit_3.setObjectName(u"lineEdit_3") 

        self.verticalLayout_2.addWidget(self.lineEdit_3) 

        self.label_6 = QLabel(self.verticalLayoutWidget_2) 
        self.label_6.setObjectName(u"label_6") 

        self.verticalLayout_2.addWidget(self.label_6) 
        self.lineEdit_4 = QLineEdit(self.verticalLayoutWidget_2) 
        self.lineEdit_4.setObjectName(u"lineEdit_4") 

        self.verticalLayout_2.addWidget(self.lineEdit_4) 
 
        self.label_3 = QLabel(Dialog) 
        self.label_3.setObjectName(u"label_3") 
        self.label_3.setGeometry(QRect(30, 100, 231, 31)) 
        self.label_4 = QLabel(Dialog) 
        self.label_4.setObjectName(u"label_4") 
        self.label_4.setGeometry(QRect(360, 50, 251, 31)) 
        self.pushButton = QPushButton(Dialog) 
        self.pushButton.setObjectName(u"pushButton") 
        self.pushButton.setGeometry(QRect(100, 390, 111, 31))  
        self.retranslateUi(Dialog) 

        QMetaObject.connectSlotsByName(Dialog) 
    # setupUi 
 
    def retranslateUi(self, Dialog): 
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None)) 
        self.label.setText(QCoreApplication.translate("Dialog", u"Remitente:", None)) 
        self.label_2.setText(QCoreApplication.translate("Dialog", u"Receptor:", None)) 
        self.label_5.setText(QCoreApplication.translate("Dialog", u"Monto", None)) 
        self.label_6.setText(QCoreApplication.translate("Dialog", u"Bloque a insertar", None)) 
        self.label_3.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p><span style=\" font-size:14pt;\">Datos:</span></p></body></html>", None))  
        self.label_4.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p><span style=\" font-size:14pt;\">Resultados de la Modificaci\u00f3n:</span></p><p><br/></p></body></html>", None)) 
        self.pushButton.setText(QCoreApplication.translate("Dialog", u"MODIFICAR", None)) 
 
    # retranslateUi
    def clearLayout(self, layout):
        while layout.count():
            child = layout.takeAt(0)
            if child.widget():
                child.widget().deleteLater()
                
    def addData(self, res):
        for i in res:
            temp = QLabel(i)
            self.verticalLayout.addWidget(temp)