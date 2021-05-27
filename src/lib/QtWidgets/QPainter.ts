import addon from '../utils/addon';
import { Component, NativeElement } from '../core/Component';
import { QPainterPath } from '../QtWidgets/QPainterPath';
import { PenStyle } from '../QtEnums';
import { QColor } from '../QtGui/QColor';
import { QPoint } from '../QtCore/QPoint';
import { QPen } from '../QtGui/QPen';

/**

> Lets you paint on widgets.

* **This class is a JS wrapper around Qt's [QPainter class](https://doc.qt.io/qt-5/qpainter.html)**

Note: QPainter works only inside the paint event.

### Example

```javascript

import { FlexLayout, WidgetEventTypes, QMainWindow, QPainter, QWidget } from '@nodegui/nodegui';

const win = new QMainWindow();
const center = new QWidget();
const layout = new FlexLayout();
center.setLayout(layout);
win.resize(200, 200);

win.addEventListener(WidgetEventTypes.Paint, () => {
    const painter = new QPainter(win);
    painter.drawText(20, 20, 'Hello');
    painter.end();
});
win.show();
(global as any).win = win;

```

## Advanced example:

https://github.com/nodegui/examples/blob/master/nodegui/custom-native-widget-qpainter
*/
export class QPainter extends Component {
    native: NativeElement;
    constructor();
    constructor(device: Component);
    constructor(device?: Component) {
        let native;
        if (device) {
            native = new addon.QPainter(device.native);
        } else {
            native = new addon.QPainter();
        }
        super();
        this.native = native;
    }

    drawText(x: number, y: number, text: string): void {
        return this.native.drawText(x, y, text);
    }

    drawPath(path: QPainterPath): void {
        return this.native.drawPath(path.native);
    }

    strokePath(path: QPainterPath, pen: QPen): void {
        return this.native.strokePath(path.native, pen.native);
    }

    begin(device: Component): boolean {
        return this.native.begin(device.native);
    }

    beginNativePainting(): void {
        this.native.beginNativePainting();
    }

    end(): boolean {
        return this.native.end();
    }

    endNativePainting(): void {
        this.native.endNativePainting();
    }

    rotate(angle: number): void {
        this.native.rotate(angle);
    }

    setPen(arg: PenStyle | QColor | QPen): void {
        if (typeof arg == 'number') {
            this.native.setPen(arg, 'style');
        } else if (arg instanceof QColor) {
            this.native.setPen(arg.native, 'color');
        } else if (arg instanceof QPen) {
            this.native.setPen(arg.native, 'pen');
        }
    }

    setRenderHint(hint: RenderHint, on = true): void {
        this.native.setRenderHint(hint, on);
    }

    drawEllipse(x: number, y: number, width: number, height: number): void {
        return this.native.drawEllipse(x, y, width, height);
    }

    drawPie(x: number, y: number, width: number, height: number, startAngle: number, sweepLength: number): void {
        return this.native.drawPie(x, y, width, height, startAngle, sweepLength);
    }

    drawLine(x1: number, y1: number, x2: number, y2: number): void {
        this.native.drawLine(x1, y1, x2, y2);
    }

    scale(sx: number, sy: number): void {
        this.native.scale(sx, sy);
    }

    translate(dx: number, dy: number): void {
        this.native.translate(dx, dy);
    }

    drawConvexPolygon(points: QPoint[]): void {
        const nativePoints = points.map((point) => point.native);
        this.native.drawConvexPolygon(nativePoints);
    }

    save(): void {
        this.native.save();
    }

    restore(): void {
        this.native.restore();
    }

    setBrush(color: QColor): void {
        this.native.setBrush(color.native);
    }
}

export enum RenderHint {
    Antialiasing = 0x01,
    TextAntialiasing = 0x02,
    SmoothPixmapTransform = 0x04,
    HighQualityAntialiasing = 0x08,
    NonCosmeticDefaultPen = 0x10,
    Qt4CompatiblePainting = 0x20,
    LosslessImageRendering = 0x40,
}
