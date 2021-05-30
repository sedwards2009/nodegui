import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';

export enum QOpenGLBufferType {
  VertexBuffer=0x8892,
  IndexBuffer=0x8893,
  PixelPackBuffer=0x88EB,
  PixelUnpackBuffer=0x88EC
}

export class QOpenGLBuffer extends Component {
    native: NativeElement;

    constructor(arg?: QOpenGLBufferType) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLBuffer();
        } else {
            this.native = new addon.QOpenGLBuffer(arg);
        }
    }

    allocate(bytesCount: number): void {
        this.native.allocate(bytesCount);
    }

    bind(): void {
        return this.native.bind();
    }

    create(): boolean {
        return this.native.create();
    }

    destroy(): void {
        this.native.destroy();
    }

    release(): void {
        this.native.release();
    }

    write(offset: number, arrayBuffer: ArrayBuffer, count: number): void {
        this.native.write(offset, arrayBuffer, count);
    }
}
