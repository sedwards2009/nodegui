import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';


export class QSurfaceFormat extends Component {
    native: NativeElement;

    constructor() {
        super();
        this.native = new addon.QSurfaceFormat();
    }

    setDepthBufferSize(depth: number): void {
        this.native.setDepthBufferSize(depth);
    }

    setStencilBufferSize(size: number): void {
        this.native.setStencilBufferSize(size);
    }

    static setDefaultFormat(format: QSurfaceFormat): void {
        addon.QSurfaceFormat.setDefaultFormat(format);
    }
}
