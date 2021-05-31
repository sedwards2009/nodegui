import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { QObject } from '../QtCore/QObject';
import { QOpenGLFunctions } from './QOpenGLFunctions';
import { QImage } from './QImage';

enum MipMapGeneration {
  GenerateMipMaps = 0,
  DontGenerateMipMaps = 1
}


export class QOpenGLTexture extends Component {
    native: NativeElement;

    constructor(arg?: NativeElement | QImage, arg2?: MipMapGeneration) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLTexture();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else {
                if (arg2 === undefined) {
                    arg2 = MipMapGeneration.GenerateMipMaps;
                }
                this.native = new addon.QOpenGLTexture(arg.native, arg2);
            }
        }
    }

    bind(): void {
        this.native.bind();
    }
}
