import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { QOpenGLContext } from './QOpenGLContext';
import { QOpenGLShaderProgram } from './QOpenGLShaderProgram';
import { QOpenGLBuffer } from './QOpenGLBuffer';

/**

> Access to OpenGL ES 2.0, 3.0, 3.1 and 3.2 functions.

Note: Unlike the C++ `QOpenGLExtraFunctions` class, this version drops the `gl`
prefix for method and constant names to more closely match WebGL.

*/
export class QOpenGLExtraFunctions extends Component {
    native: NativeElement;

    readonly CURRENT_BIT = 0x00000001;
    readonly POINT_BIT = 0x00000002;
    readonly LINE_BIT = 0x00000004;
    readonly POLYGON_BIT = 0x00000008;
    readonly POLYGON_STIPPLE_BIT = 0x00000010;
    readonly PIXEL_MODE_BIT = 0x00000020;
    readonly LIGHTING_BIT = 0x00000040;
    readonly FOG_BIT = 0x00000080;
    readonly ACCUM_BUFFER_BIT = 0x00000200;
    readonly VIEWPORT_BIT = 0x00000800;
    readonly TRANSFORM_BIT = 0x00001000;
    readonly ENABLE_BIT = 0x00002000;
    readonly HINT_BIT = 0x00008000;
    readonly EVAL_BIT = 0x00010000;
    readonly LIST_BIT = 0x00020000;
    readonly TEXTURE_BIT = 0x00040000;
    readonly SCISSOR_BIT = 0x00080000;
    readonly ALL_ATTRIB_BITS = 0xffffffff;

    readonly ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8b8a;
    readonly ACTIVE_ATTRIBUTES = 0x8b89;
    readonly ACTIVE_TEXTURE = 0x84e0;
    readonly ACTIVE_UNIFORM_MAX_LENGTH = 0x8b87;
    readonly ACTIVE_UNIFORMS = 0x8b86;
    readonly ALIASED_LINE_WIDTH_RANGE = 0x846e;
    readonly ALIASED_POINT_SIZE_RANGE = 0x846d;
    readonly ALPHA = 0x1906;
    readonly ALPHA_BITS = 0x0d55;
    readonly ALWAYS = 0x0207;
    readonly ARRAY_BUFFER = 0x8892;
    readonly ARRAY_BUFFER_BINDING = 0x8894;
    readonly ATTACHED_SHADERS = 0x8b85;
    readonly BACK = 0x0405;
    readonly BLEND = 0x0be2;
    readonly BLEND_COLOR = 0x8005;
    readonly BLEND_DST_ALPHA = 0x80ca;
    readonly BLEND_DST_RGB = 0x80c8;
    readonly BLEND_EQUATION = 0x8009;
    readonly BLEND_EQUATION_ALPHA = 0x883d;
    readonly BLEND_EQUATION_RGB = 0x8009;
    readonly BLEND_SRC_ALPHA = 0x80cb;
    readonly BLEND_SRC_RGB = 0x80c9;
    readonly BLUE_BITS = 0x0d54;
    readonly BOOL = 0x8b56;
    readonly BOOL_VEC2 = 0x8b57;
    readonly BOOL_VEC3 = 0x8b58;
    readonly BOOL_VEC4 = 0x8b59;
    readonly BUFFER_SIZE = 0x8764;
    readonly BUFFER_USAGE = 0x8765;
    readonly BYTE = 0x1400;
    readonly CCW = 0x0901;
    readonly CLAMP_TO_EDGE = 0x812f;
    readonly COLOR_ATTACHMENT0 = 0x8ce0;
    readonly COLOR_BUFFER_BIT = 0x00004000;
    readonly COLOR_CLEAR_VALUE = 0x0c22;
    readonly COLOR_WRITEMASK = 0x0c23;
    readonly COMPILE_STATUS = 0x8b81;
    readonly COMPRESSED_TEXTURE_FORMATS = 0x86a3;
    readonly CONSTANT_ALPHA = 0x8003;
    readonly CONSTANT_COLOR = 0x8001;
    readonly CULL_FACE = 0x0b44;
    readonly CULL_FACE_MODE = 0x0b45;
    readonly CURRENT_PROGRAM = 0x8b8d;
    readonly CURRENT_VERTEX_ATTRIB = 0x8626;
    readonly CW = 0x0900;
    readonly DECR = 0x1e03;
    readonly DECR_WRAP = 0x8508;
    readonly DELETE_STATUS = 0x8b80;
    readonly DEPTH_ATTACHMENT = 0x8d00;
    readonly DEPTH_BITS = 0x0d56;
    readonly DEPTH_BUFFER_BIT = 0x00000100;
    readonly DEPTH_CLEAR_VALUE = 0x0b73;
    readonly DEPTH_COMPONENT = 0x1902;
    readonly DEPTH_COMPONENT16 = 0x81a5;
    readonly DEPTH_FUNC = 0x0b74;
    readonly DEPTH_RANGE = 0x0b70;
    readonly DEPTH_TEST = 0x0b71;
    readonly DEPTH_WRITEMASK = 0x0b72;
    readonly DITHER = 0x0bd0;
    readonly DONT_CARE = 0x1100;
    readonly DST_ALPHA = 0x0304;
    readonly DST_COLOR = 0x0306;
    readonly DYNAMIC_DRAW = 0x88e8;
    readonly ELEMENT_ARRAY_BUFFER = 0x8893;
    readonly ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
    readonly EQUAL = 0x0202;
    readonly EXTENSIONS = 0x1f03;
    readonly FALSE = 0;
    readonly FASTEST = 0x1101;
    readonly FIXED = 0x140c;
    readonly FLOAT = 0x1406;
    readonly FLOAT_MAT2 = 0x8b5a;
    readonly FLOAT_MAT3 = 0x8b5b;
    readonly FLOAT_MAT4 = 0x8b5c;
    readonly FLOAT_VEC2 = 0x8b50;
    readonly FLOAT_VEC3 = 0x8b51;
    readonly FLOAT_VEC4 = 0x8b52;
    readonly FRAGMENT_SHADER = 0x8b30;
    readonly FRAMEBUFFER = 0x8d40;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8cd1;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8cd0;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8cd3;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8cd2;
    readonly FRAMEBUFFER_BINDING = 0x8ca6;
    readonly FRAMEBUFFER_COMPLETE = 0x8cd5;
    readonly FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8cd6;
    readonly FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8cd9;
    readonly FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8cd7;
    readonly FRAMEBUFFER_UNSUPPORTED = 0x8cdd;
    readonly FRONT = 0x0404;
    readonly FRONT_AND_BACK = 0x0408;
    readonly FRONT_FACE = 0x0b46;
    readonly FUNC_ADD = 0x8006;
    readonly FUNC_REVERSE_SUBTRACT = 0x800b;
    readonly FUNC_SUBTRACT = 0x800a;
    readonly GENERATE_MIPMAP_HINT = 0x8192;
    readonly GEQUAL = 0x0206;
    readonly GREATER = 0x0204;
    readonly GREEN_BITS = 0x0d53;
    readonly HIGH_FLOAT = 0x8df2;
    readonly HIGH_INT = 0x8df5;
    readonly IMPLEMENTATION_COLOR_READ_FORMAT = 0x8b9b;
    readonly IMPLEMENTATION_COLOR_READ_TYPE = 0x8b9a;
    readonly INCR = 0x1e02;
    readonly INCR_WRAP = 0x8507;
    readonly INFO_LOG_LENGTH = 0x8b84;
    readonly INT = 0x1404;
    readonly INT_VEC2 = 0x8b53;
    readonly INT_VEC3 = 0x8b54;
    readonly INT_VEC4 = 0x8b55;
    readonly INVALID_ENUM = 0x0500;
    readonly INVALID_FRAMEBUFFER_OPERATION = 0x0506;
    readonly INVALID_OPERATION = 0x0502;
    readonly INVALID_VALUE = 0x0501;
    readonly INVERT = 0x150a;
    readonly KEEP = 0x1e00;
    readonly LEQUAL = 0x0203;
    readonly LESS = 0x0201;
    readonly LINEAR = 0x2601;
    readonly LINEAR_MIPMAP_LINEAR = 0x2703;
    readonly LINEAR_MIPMAP_NEAREST = 0x2701;
    readonly LINE_LOOP = 0x0002;
    readonly LINES = 0x0001;
    readonly LINE_STRIP = 0x0003;
    readonly LINE_WIDTH = 0x0b21;
    readonly LINK_STATUS = 0x8b82;
    readonly LOW_FLOAT = 0x8df0;
    readonly LOW_INT = 0x8df3;
    readonly LUMINANCE = 0x1909;
    readonly LUMINANCE_ALPHA = 0x190a;
    readonly MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8b4d;
    readonly MAX_CUBE_MAP_TEXTURE_SIZE = 0x851c;
    readonly MAX_FRAGMENT_UNIFORM_VECTORS = 0x8dfd;
    readonly MAX_RENDERBUFFER_SIZE = 0x84e8;
    readonly MAX_TEXTURE_IMAGE_UNITS = 0x8872;
    readonly MAX_TEXTURE_SIZE = 0x0d33;
    readonly MAX_VARYING_VECTORS = 0x8dfc;
    readonly MAX_VERTEX_ATTRIBS = 0x8869;
    readonly MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8b4c;
    readonly MAX_VERTEX_UNIFORM_VECTORS = 0x8dfb;
    readonly MAX_VIEWPORT_DIMS = 0x0d3a;
    readonly MEDIUM_FLOAT = 0x8df1;
    readonly MEDIUM_INT = 0x8df4;
    readonly MIRRORED_REPEAT = 0x8370;
    readonly NEAREST = 0x2600;
    readonly NEAREST_MIPMAP_LINEAR = 0x2702;
    readonly NEAREST_MIPMAP_NEAREST = 0x2700;
    readonly NEVER = 0x0200;
    readonly NICEST = 0x1102;
    readonly NO_ERROR = 0;
    readonly NONE = 0;
    readonly NOTEQUAL = 0x0205;
    readonly NUM_COMPRESSED_TEXTURE_FORMATS = 0x86a2;
    readonly NUM_SHADER_BINARY_FORMATS = 0x8df9;
    readonly ONE = 1;
    readonly ONE_MINUS_CONSTANT_ALPHA = 0x8004;
    readonly ONE_MINUS_CONSTANT_COLOR = 0x8002;
    readonly ONE_MINUS_DST_ALPHA = 0x0305;
    readonly ONE_MINUS_DST_COLOR = 0x0307;
    readonly ONE_MINUS_SRC_ALPHA = 0x0303;
    readonly ONE_MINUS_SRC_COLOR = 0x0301;
    readonly OUT_OF_MEMORY = 0x0505;
    readonly PACK_ALIGNMENT = 0x0d05;
    readonly POINTS = 0x0000;
    readonly POLYGON_OFFSET_FACTOR = 0x8038;
    readonly POLYGON_OFFSET_FILL = 0x8037;
    readonly POLYGON_OFFSET_UNITS = 0x2a00;
    readonly RED_BITS = 0x0d52;
    readonly RENDERBUFFER = 0x8d41;
    readonly RENDERBUFFER_ALPHA_SIZE = 0x8d53;
    readonly RENDERBUFFER_BINDING = 0x8ca7;
    readonly RENDERBUFFER_BLUE_SIZE = 0x8d52;
    readonly RENDERBUFFER_DEPTH_SIZE = 0x8d54;
    readonly RENDERBUFFER_GREEN_SIZE = 0x8d51;
    readonly RENDERBUFFER_HEIGHT = 0x8d43;
    readonly RENDERBUFFER_INTERNAL_FORMAT = 0x8d44;
    readonly RENDERBUFFER_RED_SIZE = 0x8d50;
    readonly RENDERBUFFER_STENCIL_SIZE = 0x8d55;
    readonly RENDERBUFFER_WIDTH = 0x8d42;
    readonly RENDERER = 0x1f01;
    readonly REPEAT = 0x2901;
    readonly REPLACE = 0x1e01;
    readonly RGB = 0x1907;
    readonly RGB565 = 0x8d62;
    readonly RGB5_A1 = 0x8057;
    readonly RGBA = 0x1908;
    readonly RGBA4 = 0x8056;
    readonly BGRA = 0x80e1;
    readonly SAMPLE_ALPHA_TO_COVERAGE = 0x809e;
    readonly SAMPLE_BUFFERS = 0x80a8;
    readonly SAMPLE_COVERAGE = 0x80a0;
    readonly SAMPLE_COVERAGE_INVERT = 0x80ab;
    readonly SAMPLE_COVERAGE_VALUE = 0x80aa;
    readonly SAMPLER_2D = 0x8b5e;
    readonly SAMPLER_CUBE = 0x8b60;
    readonly SAMPLES = 0x80a9;
    readonly SCISSOR_BOX = 0x0c10;
    readonly SCISSOR_TEST = 0x0c11;
    readonly SHADER_BINARY_FORMATS = 0x8df8;
    readonly SHADER_COMPILER = 0x8dfa;
    readonly SHADER_SOURCE_LENGTH = 0x8b88;
    readonly SHADER_TYPE = 0x8b4f;
    readonly SHADING_LANGUAGE_VERSION = 0x8b8c;
    readonly SHORT = 0x1402;
    readonly SRC_ALPHA = 0x0302;
    readonly SRC_ALPHA_SATURATE = 0x0308;
    readonly SRC_COLOR = 0x0300;
    readonly STATIC_DRAW = 0x88e4;
    readonly STENCIL_ATTACHMENT = 0x8d20;
    readonly STENCIL_BACK_FAIL = 0x8801;
    readonly STENCIL_BACK_FUNC = 0x8800;
    readonly STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
    readonly STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
    readonly STENCIL_BACK_REF = 0x8ca3;
    readonly STENCIL_BACK_VALUE_MASK = 0x8ca4;
    readonly STENCIL_BACK_WRITEMASK = 0x8ca5;
    readonly STENCIL_BITS = 0x0d57;
    readonly STENCIL_BUFFER_BIT = 0x00000400;
    readonly STENCIL_CLEAR_VALUE = 0x0b91;
    readonly STENCIL_FAIL = 0x0b94;
    readonly STENCIL_FUNC = 0x0b92;
    readonly STENCIL_INDEX = 0x1901;
    readonly STENCIL_INDEX8 = 0x8d48;
    readonly STENCIL_PASS_DEPTH_FAIL = 0x0b95;
    readonly STENCIL_PASS_DEPTH_PASS = 0x0b96;
    readonly STENCIL_REF = 0x0b97;
    readonly STENCIL_TEST = 0x0b90;
    readonly STENCIL_VALUE_MASK = 0x0b93;
    readonly STENCIL_WRITEMASK = 0x0b98;
    readonly STREAM_DRAW = 0x88e0;
    readonly SUBPIXEL_BITS = 0x0d50;
    readonly TEXTURE0 = 0x84c0;
    readonly TEXTURE = 0x1702;
    readonly TEXTURE10 = 0x84ca;
    readonly TEXTURE1 = 0x84c1;
    readonly TEXTURE11 = 0x84cb;
    readonly TEXTURE12 = 0x84cc;
    readonly TEXTURE13 = 0x84cd;
    readonly TEXTURE14 = 0x84ce;
    readonly TEXTURE15 = 0x84cf;
    readonly TEXTURE16 = 0x84d0;
    readonly TEXTURE17 = 0x84d1;
    readonly TEXTURE18 = 0x84d2;
    readonly TEXTURE19 = 0x84d3;
    readonly TEXTURE20 = 0x84d4;
    readonly TEXTURE2 = 0x84c2;
    readonly TEXTURE21 = 0x84d5;
    readonly TEXTURE22 = 0x84d6;
    readonly TEXTURE23 = 0x84d7;
    readonly TEXTURE24 = 0x84d8;
    readonly TEXTURE25 = 0x84d9;
    readonly TEXTURE26 = 0x84da;
    readonly TEXTURE27 = 0x84db;
    readonly TEXTURE28 = 0x84dc;
    readonly TEXTURE29 = 0x84dd;
    readonly TEXTURE_2D = 0x0de1;
    readonly TEXTURE30 = 0x84de;
    readonly TEXTURE3 = 0x84c3;
    readonly TEXTURE31 = 0x84df;
    readonly TEXTURE4 = 0x84c4;
    readonly TEXTURE5 = 0x84c5;
    readonly TEXTURE6 = 0x84c6;
    readonly TEXTURE7 = 0x84c7;
    readonly TEXTURE8 = 0x84c8;
    readonly TEXTURE9 = 0x84c9;
    readonly TEXTURE_BINDING_2D = 0x8069;
    readonly TEXTURE_BINDING_CUBE_MAP = 0x8514;
    readonly TEXTURE_CUBE_MAP = 0x8513;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851a;
    readonly TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
    readonly TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
    readonly TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
    readonly TEXTURE_MAG_FILTER = 0x2800;
    readonly TEXTURE_MIN_FILTER = 0x2801;
    readonly TEXTURE_WRAP_S = 0x2802;
    readonly TEXTURE_WRAP_T = 0x2803;
    readonly TRIANGLE_FAN = 0x0006;
    readonly TRIANGLES = 0x0004;
    readonly TRIANGLE_STRIP = 0x0005;
    readonly TRUE = 1;
    readonly UNPACK_ALIGNMENT = 0x0cf5;
    readonly UNSIGNED_BYTE = 0x1401;
    readonly UNSIGNED_INT = 0x1405;
    readonly UNSIGNED_SHORT = 0x1403;
    readonly UNSIGNED_SHORT_4_4_4_4 = 0x8033;
    readonly UNSIGNED_SHORT_5_5_5_1 = 0x8034;
    readonly UNSIGNED_SHORT_5_6_5 = 0x8363;
    readonly VALIDATE_STATUS = 0x8b83;
    readonly VENDOR = 0x1f00;
    readonly VERSION = 0x1f02;
    readonly VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889f;
    readonly VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
    readonly VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886a;
    readonly VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
    readonly VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
    readonly VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
    readonly VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
    readonly VERTEX_SHADER = 0x8b31;
    readonly VIEWPORT = 0x0ba2;
    readonly ZERO = 0;

    constructor(arg?: NativeElement | QOpenGLContext) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLExtraFunctions();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else if (arg.native) {
                this.native = new addon.QOpenGLExtraFunctions((arg as QOpenGLContext).native);
            } else {
                this.native = new addon.QOpenGLExtraFunctions();
            }
        }
    }

    initializeOpenGLFunctions(): void {
        this.native.initializeOpenGLFunctions();
    }

    bindBuffer(target: number, buffer: QOpenGLBuffer | number): void {
        const bufferId = typeof buffer === 'object' ? buffer.bufferId() : buffer;
        this.native.glBindBuffer(target, bufferId);
    }

    clearColor(red: number, green: number, blue: number, alpha: number): void {
        this.native.glClearColor(red, green, blue, alpha);
    }

    clear(mask: number): void {
        this.native.glClear(mask);
    }

    frontFace(arg: number): void {
        this.native.glFrontFace(arg);
    }

    cullFace(arg: number): void {
        this.native.glCullFace(arg);
    }

    disable(arg: number): void {
        this.native.glDisable(arg);
    }

    enable(arg: number): void {
        this.native.glEnable(arg);
    }

    drawArrays(mode: GLenum, first: number, count: number): void {
        this.native.glDrawArrays(mode, first, count);
    }

    useProgram(program: QOpenGLShaderProgram): void {
        this.native.glUseProgram(program.programId());
    }

    getString(name: number): string {
        return this.native.glGetString(name);
    }

    depthFunc(func: number): void {
        this.native.glDepthFunc(func);
    }

    genVertexArrays(numberOfArrays: number): number[] {
        const result: number[] = [];
        for (let i = 0; i < numberOfArrays; i++) {
            result.push(this.native.glGenVertexArray());
        }
        return result;
    }

    bindVertexArray(vertexArray: number): void {
        this.native.glBindVertexArray(vertexArray);
    }

    enableVertexAttribArray(index: number): void {
        this.native.glEnableVertexAttribArray(index);
    }

    vertexAttribPointer(index: number, size: number, type: number, normalized: number | boolean, stride: number): void {
        const normalizedBoolean = Boolean(normalized);
        this.native.glVertexAttribPointer(index, size, type, normalizedBoolean, stride);
    }

    genBuffers(numberOfBuffers: number): number[] {
        const result: number[] = [];
        for (let i = 0; i < numberOfBuffers; i++) {
            result.push(this.native.glGenBuffer());
        }
        return result;
    }

    bufferData(target: number, size: number, arrayBuffer: ArrayBuffer, usage: number): void {
        this.native.glBufferData(target, size, arrayBuffer, usage);
    }
}
