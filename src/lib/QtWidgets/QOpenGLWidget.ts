import addon from '../utils/addon';
import { NodeWidget, QWidgetSignals } from './QWidget';
import { NativeElement } from '../core/Component';

/**

> Create and control text.

* **This class is a JS wrapper around Qt's [QOpenGLWidget class](https://doc.qt.io/qt-5/qopenglwidget.html)**

A `QOpenGLWidget` provides ability to render its contents using OpenGL.

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
    // setAlignment(alignment: AlignmentFlag): void {
    //     this.setProperty('alignment', alignment);
    // }
    // alignment(): AlignmentFlag {
    //     return this.property('alignment').toInt();
    // }
    // hasSelectedText(): boolean {
    //     return this.property('hasSelectedText').toBool();
    // }
    // setIndent(indent: number): void {
    //     this.setProperty('indent', indent);
    // }
    // indent(): number {
    //     return this.property('indent').toInt();
    // }
    // setMargin(margin: number): void {
    //     this.setProperty('margin', margin);
    // }
    // margin(): number {
    //     return this.property('margin').toInt();
    // }
    // setOpenExternalLinks(open: boolean): void {
    //     this.setProperty('openExternalLinks', open);
    // }
    // openExternalLinks(): boolean {
    //     return this.property('openExternalLinks').toBool();
    // }
    // setScaledContents(scaled: boolean): void {
    //     this.setProperty('scaledContents', scaled);
    // }
    // hasScaledContents(): boolean {
    //     return this.property('scaledContents').toBool();
    // }
    // selectedText(): string {
    //     return this.property('selectedText').toString();
    // }
    // setText(text: string | number): void {
    //     this.setProperty('text', `${text}`);
    // }
    // text(): string {
    //     return this.property('text').toString();
    // }
    // setTextFormat(format: TextFormat): void {
    //     this.setProperty('textFormat', format);
    // }
    // textFormat(): TextFormat {
    //     return this.property('textFormat').toInt();
    // }
    // setTextInteractionFlags(flags: TextInteractionFlag): void {
    //     this.setProperty('textInteractionFlags', flags);
    // }
    // textInteractionFlags(): TextInteractionFlag {
    //     return this.property('textInteractionFlags').toInt();
    // }
    // setWordWrap(on: boolean): void {
    //     this.setProperty('wordWrap', on);
    // }
    // wordWrap(): boolean {
    //     return this.property('wordWrap').toBool();
    // }
    // setSelection(start: number, length: number): void {
    //     this.native.setSelection(start, length);
    // }
    // selectionStart(): number {
    //     return this.native.selectionStart();
    // }
    // setBuddy(buddy: NodeWidget<any>): void {
    //     this.native.setBuddy(buddy.native);
    //     this._buddy = buddy;
    // }
    // buddy(): NodeWidget<any> | null {
    //     if (this._buddy) {
    //         return this._buddy;
    //     }
    //     return null;
    // }
    // setMovie(movie: QMovie): void {
    //     this.native.setMovie(movie.native);
    //     this._movie = movie;
    // }
    // movie(): QMovie | undefined {
    //     return this._movie;
    // }
    // setPicture(picture: QPicture): void {
    //     this.native.setPicture(picture.native);
    //     this._picture = picture;
    // }
    // picture(): QPicture | undefined {
    //     return this._picture;
    // }
    // setPixmap(pixMap: QPixmap): void {
    //     this.native.setPixmap(pixMap.native);
    //     this._pixmap = pixMap;
    // }
    // pixmap(): QPixmap | undefined {
    //     return this._pixmap;
    // }
    // setNumDouble(num: number): void {
    //     this.native.setNumDouble(num);
    // }
    // setNumInt(num: number): void {
    //     this.native.setNumInt(num);
    // }
    // clear(): void {
    //     this.native.clear();
    // }
}

export interface QOpenGLWidgetSignals extends QWidgetSignals {
}
