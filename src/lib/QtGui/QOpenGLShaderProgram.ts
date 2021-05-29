import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { QObject } from '../QtCore/QObject';
import { QOpenGLShader } from './QOpenGLShader';


export class QOpenGLShaderProgram extends Component {
    native: NativeElement;

    constructor(arg?: QObject) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLShaderProgram();
        } else {
            this.native = new addon.QOpenGLShaderProgram(arg.native);
        }
    }

    addShader(shader: QOpenGLShader): boolean {
      return this.native.addShader(shader.native);
    }

    link(): boolean {
      return this.native.link();
    }

    attributeLocation(attribute: string): number {
      return this.native.attributeLocation(attribute);
    }

    uniformLocation(uniform: string): number {
      return this.native.uniformLocation(uniform);
    }
}
