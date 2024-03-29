################################################################################
## Form generated from reading UI file 'admin.ui'
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
from PySide6.QtWidgets import (QApplication, QDialog, QLabel, QPushButton,
    QSizePolicy, QVBoxLayout, QWidget)

class Ui_Admin(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(824, 530)
        self.label_4 = QLabel(Dialog)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(426, 13, 311, 21))
        self.verticalLayoutWidget = QWidget(Dialog)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(426, 100, 381, 281))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.label = QLabel(self.verticalLayoutWidget)
        self.label.setObjectName(u"label")

        self.verticalLayout.addWidget(self.label)

        self.label_2 = QLabel(self.verticalLayoutWidget)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout.addWidget(self.label_2)

        self.label_3 = QLabel(self.verticalLayoutWidget)
        self.label_3.setObjectName(u"label_3")

        self.verticalLayout.addWidget(self.label_3)

        self.label_5 = QLabel(Dialog)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(40, 30, 181, 21))
        self.verticalLayoutWidget_2 = QWidget(Dialog)
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2")
        self.verticalLayoutWidget_2.setGeometry(QRect(50, 100, 181, 181))
        self.verticalLayout_2 = QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.load_Button = QPushButton(self.verticalLayoutWidget_2)
        self.load_Button.setObjectName(u"load_Button")

        self.verticalLayout_2.addWidget(self.load_Button)

        self.modify_Button = QPushButton(self.verticalLayoutWidget_2)
        self.modify_Button.setObjectName(u"modify_Button")

        self.verticalLayout_2.addWidget(self.modify_Button)

        self.find_Button = QPushButton(self.verticalLayoutWidget_2)
        self.find_Button.setObjectName(u"find_Button")

        self.verticalLayout_2.addWidget(self.find_Button)

        self.home_Button = QPushButton(Dialog)
        self.home_Button.setObjectName(u"home_Button")
        self.home_Button.setGeometry(QRect(720, 460, 61, 51))

        self.label_loaded = QLabel(Dialog)
        self.label_loaded.setObjectName(u"label_loaded")
        self.label_loaded.setGeometry(QRect(410, 400, 211, 51))

        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.label.setText(QCoreApplication.translate("Dialog", u"N\u00famero de Bloques", None))
        self.label_2.setText(QCoreApplication.translate("Dialog", u"Hash Actual:", None))
        self.label_3.setText(QCoreApplication.translate("Dialog", u"TextLabel", None))
        self.label_4.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">BlockChain Data</span></p></body></html>", None))
        self.label_5.setText(QCoreApplication.translate("Dialog", u"<html><head/><body><p><span style=\" font-size:14pt;\">Funciones:</span></p></body></html>", None))
        self.load_Button.setText(QCoreApplication.translate("Dialog", u"Cargar Data", None))
        self.modify_Button.setText(QCoreApplication.translate("Dialog", u"Modificar Data", None))
        self.find_Button.setText(QCoreApplication.translate("Dialog", u"Buscar", None))
        self.home_Button.setText(QCoreApplication.translate("Dialog", u"HOME", None))
        self.label_loaded.setText(QCoreApplication.translate("Dialog", u"", None))
    # retranslateUi