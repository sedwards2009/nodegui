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

    bind(): boolean {
        return this.native.bind();
    }

    link(): boolean {
        return this.native.link();
    }

    attributeLocation(attribute: string): number {
        return this.native.attributeLocation(attribute);
    }

    release(): void {
        this.native.release();
    }

    uniformLocation(uniform: string): number {
        return this.native.uniformLocation(uniform);
    }

    setUniformValue1i(location: number, value: number): void {
        this.native.setUniformValue1i(location, value);
    }

    disableAttributeArray(location: number): void {
        this.native.disableAttributeArray(location);
    }

    enableAttributeArray(location: number): void {
        this.native.enableAttributeArray(location);
    }

    setUniformMatrix4fv(location: number, data: Float32Array): void {
        this.native.setUniformMatrix4fv(location, data.buffer);
    }

    setAttributeBuffer(location: number, type: number, offset: number, tupleSize: number, stride: number=0): void {
        this.native.setAttributeBuffer(location, type, offset, tupleSize, stride);
    }

    programId(): number {
        return this.native.programId();
    }
}
