import addon from '../utils/addon';
import { NodeWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';

/**

> Create and control text.

* **This class is a JS wrapper around Qt's [QOpenGLWidget class](https://doc.qt.io/qt-5/qopenglwidget.html)**

A `QOpenGLWidget` provides ability to render its contents using OpenGL.

Unlike the C++ API, this class should not be subclassed. Instead listen to the `initializeGL`, `paintGL`, and
`resizeGL` events and perform your work there.

 */
export class QOpenGLWidget extends NodeWidget<QOpenGLWidgetSignals> {
    native: NativeElement;

    constructor();
    constructor(parent: NodeWidget<any>);
    constructor(parent?: NodeWidget<any>) {
        let native;
        if (parent) {
            native = new addon.QOpenGLWidget(parent.native);
        } else {
            native = new addon.QOpenGLWidget();
        }
        super(native);
        this.native = native;
        this.setNodeParent(parent);
    }

// TODO
    // context() const
    // GLuint 	defaultFramebufferObject() const
    // void 	doneCurrent()
    // QSurfaceFormat 	format() const
    // QImage 	grabFramebuffer()
    // bool 	isValid() const
    // void 	makeCurrent()
    // void 	setFormat(const QSurfaceFormat &format)
    // void 	setTextureFormat(GLenum texFormat)
    // void 	setUpdateBehavior(QOpenGLWidget::UpdateBehavior updateBehavior)
    // GLenum 	textureFormat() const
    // QOpenGLWidget::UpdateBehavior	updateBehavior() const

}

export interface QOpenGLWidgetSignals extends QWidgetSignals {
    initializeGL: () => void;
    paintGL: () => void;
    resizeGL: (w: number, h: number) => void;
    aboutToCompose: () => void;
    aboutToResize: () => void;
    frameSwapped: () => void;
    resized: () => void;
}
