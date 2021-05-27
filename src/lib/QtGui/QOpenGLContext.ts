import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { QObject } from '../QtCore/QObject';
import { QOpenGLFunctions } from './QOpenGLFunctions';


export class QOpenGLContext extends Component {
    native: NativeElement;

    constructor(arg?: NativeElement | QObject) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLContext();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else if (arg.native) {
                this.native = new addon.QOpenGLContext(arg.native);
            } else {
                this.native = new addon.QOpenGLContext();
            }
        }
    }

    functions(): QOpenGLFunctions {
        return new QOpenGLFunctions(this.native.functions());
    }

    /**
    Returns the last context which called makeCurrent in the current thread, or nullptr, if no context is current.
    */
    static currentContext(): QOpenGLContext {
        return new QOpenGLContext(addon.QOpenGLContext.currentContext());
    }
}
