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

console.log("Starting up");

const openGLWidget = new QOpenGLWidget();
openGLWidget.addEventListener("initializeGL", () => {
    console.log("initializeGL received");
});
openGLWidget.addEventListener("paintGL", () => {
    console.log("paintGL received");
});
openGLWidget.addEventListener("resizeGL", (w, h) => {
    console.log(`resizeGL received w: ${w} h: ${h}`);
});

gridLayout.addWidget(openGLWidget, 1, 0);

win.setCentralWidget(centralWidget);

win.show();
(global as any).win = win;
