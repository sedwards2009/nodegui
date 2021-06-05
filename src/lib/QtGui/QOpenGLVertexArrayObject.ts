import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';

export class QOpenGLVertexArrayObject extends Component {
    native: NativeElement;

    constructor() {
        super();

        this.native = new addon.QOpenGLVertexArrayObject();
    }

    bind(): void {
      this.native.bind();
    }

    create(): boolean {
      return this.native.create();
    }

    release(): void {
      this.native.release();
    }
}
