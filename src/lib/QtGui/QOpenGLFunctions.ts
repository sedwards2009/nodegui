import addon from '../utils/addon';
import { NativeElement, Component } from '../core/Component';
import { checkIfNativeElement } from '../utils/helpers';
import { QOpenGLContext } from './QOpenGLContext';
import { QOpenGLShaderProgram } from './QOpenGLShaderProgram';
import { QOpenGLBuffer } from './QOpenGLBuffer';

/**

> Access to OpenGL ES 2.0 functions.

Note: Unlike the C++ `QOpenGLFunctions` class, this version drops the `gl`
prefix for method and constant names to more closely match WebGL.

*/
export class QOpenGLFunctions extends Component {
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
    readonly ALL_ATTRIB_BITS = 0xFFFFFFFF;

    readonly ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
    readonly ACTIVE_ATTRIBUTES = 0x8B89;
    readonly ACTIVE_TEXTURE = 0x84E0;
    readonly ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
    readonly ACTIVE_UNIFORMS = 0x8B86;
    readonly ALIASED_LINE_WIDTH_RANGE = 0x846E;
    readonly ALIASED_POINT_SIZE_RANGE = 0x846D;
    readonly ALPHA = 0x1906;
    readonly ALPHA_BITS = 0x0D55;
    readonly ALWAYS = 0x0207;
    readonly ARRAY_BUFFER = 0x8892;
    readonly ARRAY_BUFFER_BINDING = 0x8894;
    readonly ATTACHED_SHADERS = 0x8B85;
    readonly BACK = 0x0405;
    readonly BLEND = 0x0BE2;
    readonly BLEND_COLOR = 0x8005;
    readonly BLEND_DST_ALPHA = 0x80CA;
    readonly BLEND_DST_RGB = 0x80C8;
    readonly BLEND_EQUATION = 0x8009;
    readonly BLEND_EQUATION_ALPHA = 0x883D;
    readonly BLEND_EQUATION_RGB = 0x8009;
    readonly BLEND_SRC_ALPHA = 0x80CB;
    readonly BLEND_SRC_RGB = 0x80C9;
    readonly BLUE_BITS = 0x0D54;
    readonly BOOL = 0x8B56;
    readonly BOOL_VEC2 = 0x8B57;
    readonly BOOL_VEC3 = 0x8B58;
    readonly BOOL_VEC4 = 0x8B59;
    readonly BUFFER_SIZE = 0x8764;
    readonly BUFFER_USAGE = 0x8765;
    readonly BYTE = 0x1400;
    readonly CCW = 0x0901;
    readonly CLAMP_TO_EDGE = 0x812F;
    readonly COLOR_ATTACHMENT0 = 0x8CE0;
    readonly COLOR_BUFFER_BIT = 0x00004000;
    readonly COLOR_CLEAR_VALUE = 0x0C22;
    readonly COLOR_WRITEMASK = 0x0C23;
    readonly COMPILE_STATUS = 0x8B81;
    readonly COMPRESSED_TEXTURE_FORMATS = 0x86A3;
    readonly CONSTANT_ALPHA = 0x8003;
    readonly CONSTANT_COLOR = 0x8001;
    readonly CULL_FACE = 0x0B44;
    readonly CULL_FACE_MODE = 0x0B45;
    readonly CURRENT_PROGRAM = 0x8B8D;
    readonly CURRENT_VERTEX_ATTRIB = 0x8626;
    readonly CW = 0x0900;
    readonly DECR = 0x1E03;
    readonly DECR_WRAP = 0x8508;
    readonly DELETE_STATUS = 0x8B80;
    readonly DEPTH_ATTACHMENT = 0x8D00;
    readonly DEPTH_BITS = 0x0D56;
    readonly DEPTH_BUFFER_BIT = 0x00000100;
    readonly DEPTH_CLEAR_VALUE = 0x0B73;
    readonly DEPTH_COMPONENT = 0x1902;
    readonly DEPTH_COMPONENT16 = 0x81A5;
    readonly DEPTH_FUNC = 0x0B74;
    readonly DEPTH_RANGE = 0x0B70;
    readonly DEPTH_TEST = 0x0B71;
    readonly DEPTH_WRITEMASK = 0x0B72;
    readonly DITHER = 0x0BD0;
    readonly DONT_CARE = 0x1100;
    readonly DST_ALPHA = 0x0304;
    readonly DST_COLOR = 0x0306;
    readonly DYNAMIC_DRAW = 0x88E8;
    readonly ELEMENT_ARRAY_BUFFER = 0x8893;
    readonly ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
    readonly EQUAL = 0x0202;
    readonly EXTENSIONS = 0x1F03;
    readonly FALSE = 0;
    readonly FASTEST = 0x1101;
    readonly FIXED = 0x140C;
    readonly FLOAT = 0x1406;
    readonly FLOAT_MAT2 = 0x8B5A;
    readonly FLOAT_MAT3 = 0x8B5B;
    readonly FLOAT_MAT4 = 0x8B5C;
    readonly FLOAT_VEC2 = 0x8B50;
    readonly FLOAT_VEC3 = 0x8B51;
    readonly FLOAT_VEC4 = 0x8B52;
    readonly FRAGMENT_SHADER = 0x8B30;
    readonly FRAMEBUFFER = 0x8D40;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
    readonly FRAMEBUFFER_BINDING = 0x8CA6;
    readonly FRAMEBUFFER_COMPLETE = 0x8CD5;
    readonly FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
    readonly FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9;
    readonly FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
    readonly FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
    readonly FRONT = 0x0404;
    readonly FRONT_AND_BACK = 0x0408;
    readonly FRONT_FACE = 0x0B46;
    readonly FUNC_ADD = 0x8006;
    readonly FUNC_REVERSE_SUBTRACT = 0x800B;
    readonly FUNC_SUBTRACT = 0x800A;
    readonly GENERATE_MIPMAP_HINT = 0x8192;
    readonly GEQUAL = 0x0206;
    readonly GREATER = 0x0204;
    readonly GREEN_BITS = 0x0D53;
    readonly HIGH_FLOAT = 0x8DF2;
    readonly HIGH_INT = 0x8DF5;
    readonly IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
    readonly IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
    readonly INCR = 0x1E02;
    readonly INCR_WRAP = 0x8507;
    readonly INFO_LOG_LENGTH = 0x8B84;
    readonly INT = 0x1404;
    readonly INT_VEC2 = 0x8B53;
    readonly INT_VEC3 = 0x8B54;
    readonly INT_VEC4 = 0x8B55;
    readonly INVALID_ENUM = 0x0500;
    readonly INVALID_FRAMEBUFFER_OPERATION = 0x0506;
    readonly INVALID_OPERATION = 0x0502;
    readonly INVALID_VALUE = 0x0501;
    readonly INVERT = 0x150A;
    readonly KEEP = 0x1E00;
    readonly LEQUAL = 0x0203;
    readonly LESS = 0x0201;
    readonly LINEAR = 0x2601;
    readonly LINEAR_MIPMAP_LINEAR = 0x2703;
    readonly LINEAR_MIPMAP_NEAREST = 0x2701;
    readonly LINE_LOOP = 0x0002;
    readonly LINES = 0x0001;
    readonly LINE_STRIP = 0x0003;
    readonly LINE_WIDTH = 0x0B21;
    readonly LINK_STATUS = 0x8B82;
    readonly LOW_FLOAT = 0x8DF0;
    readonly LOW_INT = 0x8DF3;
    readonly LUMINANCE = 0x1909;
    readonly LUMINANCE_ALPHA = 0x190A;
    readonly MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
    readonly MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
    readonly MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
    readonly MAX_RENDERBUFFER_SIZE = 0x84E8;
    readonly MAX_TEXTURE_IMAGE_UNITS = 0x8872;
    readonly MAX_TEXTURE_SIZE = 0x0D33;
    readonly MAX_VARYING_VECTORS = 0x8DFC;
    readonly MAX_VERTEX_ATTRIBS = 0x8869;
    readonly MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
    readonly MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
    readonly MAX_VIEWPORT_DIMS = 0x0D3A;
    readonly MEDIUM_FLOAT = 0x8DF1;
    readonly MEDIUM_INT = 0x8DF4;
    readonly MIRRORED_REPEAT = 0x8370;
    readonly NEAREST = 0x2600;
    readonly NEAREST_MIPMAP_LINEAR = 0x2702;
    readonly NEAREST_MIPMAP_NEAREST = 0x2700;
    readonly NEVER = 0x0200;
    readonly NICEST = 0x1102;
    readonly NO_ERROR = 0;
    readonly NONE = 0;
    readonly NOTEQUAL = 0x0205;
    readonly NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
    readonly NUM_SHADER_BINARY_FORMATS = 0x8DF9;
    readonly ONE = 1;
    readonly ONE_MINUS_CONSTANT_ALPHA = 0x8004;
    readonly ONE_MINUS_CONSTANT_COLOR = 0x8002;
    readonly ONE_MINUS_DST_ALPHA = 0x0305;
    readonly ONE_MINUS_DST_COLOR = 0x0307;
    readonly ONE_MINUS_SRC_ALPHA = 0x0303;
    readonly ONE_MINUS_SRC_COLOR = 0x0301;
    readonly OUT_OF_MEMORY = 0x0505;
    readonly PACK_ALIGNMENT = 0x0D05;
    readonly POINTS = 0x0000;
    readonly POLYGON_OFFSET_FACTOR = 0x8038;
    readonly POLYGON_OFFSET_FILL = 0x8037;
    readonly POLYGON_OFFSET_UNITS = 0x2A00;
    readonly RED_BITS = 0x0D52;
    readonly RENDERBUFFER = 0x8D41;
    readonly RENDERBUFFER_ALPHA_SIZE = 0x8D53;
    readonly RENDERBUFFER_BINDING = 0x8CA7;
    readonly RENDERBUFFER_BLUE_SIZE = 0x8D52;
    readonly RENDERBUFFER_DEPTH_SIZE = 0x8D54;
    readonly RENDERBUFFER_GREEN_SIZE = 0x8D51;
    readonly RENDERBUFFER_HEIGHT = 0x8D43;
    readonly RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
    readonly RENDERBUFFER_RED_SIZE = 0x8D50;
    readonly RENDERBUFFER_STENCIL_SIZE = 0x8D55;
    readonly RENDERBUFFER_WIDTH = 0x8D42;
    readonly RENDERER = 0x1F01;
    readonly REPEAT = 0x2901;
    readonly REPLACE = 0x1E01;
    readonly RGB = 0x1907;
    readonly RGB565 = 0x8D62;
    readonly RGB5_A1 = 0x8057;
    readonly RGBA = 0x1908;
    readonly RGBA4 = 0x8056;
    readonly BGRA = 0x80E1;
    readonly SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
    readonly SAMPLE_BUFFERS = 0x80A8;
    readonly SAMPLE_COVERAGE = 0x80A0;
    readonly SAMPLE_COVERAGE_INVERT = 0x80AB;
    readonly SAMPLE_COVERAGE_VALUE = 0x80AA;
    readonly SAMPLER_2D = 0x8B5E;
    readonly SAMPLER_CUBE = 0x8B60;
    readonly SAMPLES = 0x80A9;
    readonly SCISSOR_BOX = 0x0C10;
    readonly SCISSOR_TEST = 0x0C11;
    readonly SHADER_BINARY_FORMATS = 0x8DF8;
    readonly SHADER_COMPILER = 0x8DFA;
    readonly SHADER_SOURCE_LENGTH = 0x8B88;
    readonly SHADER_TYPE = 0x8B4F;
    readonly SHADING_LANGUAGE_VERSION = 0x8B8C;
    readonly SHORT = 0x1402;
    readonly SRC_ALPHA = 0x0302;
    readonly SRC_ALPHA_SATURATE = 0x0308;
    readonly SRC_COLOR = 0x0300;
    readonly STATIC_DRAW = 0x88E4;
    readonly STENCIL_ATTACHMENT = 0x8D20;
    readonly STENCIL_BACK_FAIL = 0x8801;
    readonly STENCIL_BACK_FUNC = 0x8800;
    readonly STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
    readonly STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
    readonly STENCIL_BACK_REF = 0x8CA3;
    readonly STENCIL_BACK_VALUE_MASK = 0x8CA4;
    readonly STENCIL_BACK_WRITEMASK = 0x8CA5;
    readonly STENCIL_BITS = 0x0D57;
    readonly STENCIL_BUFFER_BIT = 0x00000400;
    readonly STENCIL_CLEAR_VALUE = 0x0B91;
    readonly STENCIL_FAIL = 0x0B94;
    readonly STENCIL_FUNC = 0x0B92;
    readonly STENCIL_INDEX = 0x1901;
    readonly STENCIL_INDEX8 = 0x8D48;
    readonly STENCIL_PASS_DEPTH_FAIL = 0x0B95;
    readonly STENCIL_PASS_DEPTH_PASS = 0x0B96;
    readonly STENCIL_REF = 0x0B97;
    readonly STENCIL_TEST = 0x0B90;
    readonly STENCIL_VALUE_MASK = 0x0B93;
    readonly STENCIL_WRITEMASK = 0x0B98;
    readonly STREAM_DRAW = 0x88E0;
    readonly SUBPIXEL_BITS = 0x0D50;
    readonly TEXTURE0 = 0x84C0;
    readonly TEXTURE = 0x1702;
    readonly TEXTURE10 = 0x84CA;
    readonly TEXTURE1 = 0x84C1;
    readonly TEXTURE11 = 0x84CB;
    readonly TEXTURE12 = 0x84CC;
    readonly TEXTURE13 = 0x84CD;
    readonly TEXTURE14 = 0x84CE;
    readonly TEXTURE15 = 0x84CF;
    readonly TEXTURE16 = 0x84D0;
    readonly TEXTURE17 = 0x84D1;
    readonly TEXTURE18 = 0x84D2;
    readonly TEXTURE19 = 0x84D3;
    readonly TEXTURE20 = 0x84D4;
    readonly TEXTURE2 = 0x84C2;
    readonly TEXTURE21 = 0x84D5;
    readonly TEXTURE22 = 0x84D6;
    readonly TEXTURE23 = 0x84D7;
    readonly TEXTURE24 = 0x84D8;
    readonly TEXTURE25 = 0x84D9;
    readonly TEXTURE26 = 0x84DA;
    readonly TEXTURE27 = 0x84DB;
    readonly TEXTURE28 = 0x84DC;
    readonly TEXTURE29 = 0x84DD;
    readonly TEXTURE_2D = 0x0DE1;
    readonly TEXTURE30 = 0x84DE;
    readonly TEXTURE3 = 0x84C3;
    readonly TEXTURE31 = 0x84DF;
    readonly TEXTURE4 = 0x84C4;
    readonly TEXTURE5 = 0x84C5;
    readonly TEXTURE6 = 0x84C6;
    readonly TEXTURE7 = 0x84C7;
    readonly TEXTURE8 = 0x84C8;
    readonly TEXTURE9 = 0x84C9;
    readonly TEXTURE_BINDING_2D = 0x8069;
    readonly TEXTURE_BINDING_CUBE_MAP = 0x8514;
    readonly TEXTURE_CUBE_MAP = 0x8513;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
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
    readonly UNPACK_ALIGNMENT = 0x0CF5;
    readonly UNSIGNED_BYTE = 0x1401;
    readonly UNSIGNED_INT = 0x1405;
    readonly UNSIGNED_SHORT = 0x1403;
    readonly UNSIGNED_SHORT_4_4_4_4 = 0x8033;
    readonly UNSIGNED_SHORT_5_5_5_1 = 0x8034;
    readonly UNSIGNED_SHORT_5_6_5 = 0x8363;
    readonly VALIDATE_STATUS = 0x8B83;
    readonly VENDOR = 0x1F00;
    readonly VERSION = 0x1F02;
    readonly VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
    readonly VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
    readonly VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
    readonly VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
    readonly VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
    readonly VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
    readonly VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
    readonly VERTEX_SHADER = 0x8B31;
    readonly VIEWPORT = 0x0BA2;
    readonly ZERO = 0;

    constructor(arg?: NativeElement | QOpenGLContext) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLFunctions();
        } else {
          if (checkIfNativeElement(arg)) {
            this.native = arg as NativeElement;
          } else if (arg.native) {
              this.native = new addon.QOpenGLFunctions((arg as QOpenGLContext).native);
            } else {
              this.native = new addon.QOpenGLFunctions();
            }
        }
    }

    initializeOpenGLFunctions(): void {
        this.native.initializeOpenGLFunctions();
    }

    bindBuffer(target: number, buffer: QOpenGLBuffer): void {
        this.native.glBindBuffer(target, buffer.bufferId());
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
}
