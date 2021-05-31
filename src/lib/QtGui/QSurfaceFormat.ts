import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { OpenGLContextProfile } from '../QtEnums';


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

    setProfile(profile: OpenGLContextProfile): void {
        this.native.setProfile(profile);
    }

    setMajorVersion(version: number): void {
        this.native.setMajorVersion(version);

    }

    setMinorVersion(version: number): void {
        this.native.setMinorVersion(version);

    }

    static setDefaultFormat(format: QSurfaceFormat): void {
        addon.QSurfaceFormat.setDefaultFormat(format.native);
    }
}
