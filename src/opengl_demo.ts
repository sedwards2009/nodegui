import { QMainWindow, QWidget, QOpenGLWidget, QLabel, QGridLayout } from '.';


const win = new QMainWindow();
win.resize(500, 500);
win.setObjectName('win');

win.setWindowTitle("OpenGL Test");

const centralWidget = new QWidget();

const gridLayout = new QGridLayout();
centralWidget.setLayout(gridLayout);

const messageLabel = new QLabel();
messageLabel.setText("OpenGL test");
gridLayout.addWidget(messageLabel, 0, 0);

const openGLWidget = new QOpenGLWidget();
gridLayout.addWidget(openGLWidget, 1, 0);

win.setCentralWidget(centralWidget);

win.show();
(global as any).win = win;
