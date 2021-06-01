#include "QtGui/QOpenGLShaderProgram/qopenglshaderprogram_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtCore/QObject/qobject_wrap.h"
#include "QtGui/QOpenGLShader/qopenglshader_wrap.h"

Napi::FunctionReference QOpenGLShaderProgramWrap::constructor;

Napi::Object QOpenGLShaderProgramWrap::init(Napi::Env env,
                                            Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLShaderProgram";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("addShader", &QOpenGLShaderProgramWrap::addShader),
       InstanceMethod("attributeLocation",
                      &QOpenGLShaderProgramWrap::attributeLocation),
       InstanceMethod("bind", &QOpenGLShaderProgramWrap::bind),
       InstanceMethod("disableAttributeArray",
                      &QOpenGLShaderProgramWrap::disableAttributeArray),
       InstanceMethod("enableAttributeArray",
                      &QOpenGLShaderProgramWrap::enableAttributeArray),
       InstanceMethod("link", &QOpenGLShaderProgramWrap::link),
       InstanceMethod("programId", &QOpenGLShaderProgramWrap::programId),
       InstanceMethod("release", &QOpenGLShaderProgramWrap::release),
       InstanceMethod("setAttributeBuffer",
                      &QOpenGLShaderProgramWrap::setAttributeBuffer),
       InstanceMethod("setUniformMatrix4fv",
                      &QOpenGLShaderProgramWrap::setUniformMatrix4fv),
       InstanceMethod("setUniformValue1i",
                      &QOpenGLShaderProgramWrap::setUniformValue1i),
       InstanceMethod("uniformLocation",
                      &QOpenGLShaderProgramWrap::uniformLocation),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLShaderProgramWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLShaderProgram* QOpenGLShaderProgramWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLShaderProgramWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap* parentObjectWrap =
        Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance =
        new QOpenGLShaderProgram(parentObjectWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLShaderProgram();
  } else {
    Napi::TypeError::New(env,
                         "Wrong number of arguments to "
                         "QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap()")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLShaderProgramWrap::~QOpenGLShaderProgramWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QOpenGLShaderProgramWrap::addShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(
        env,
        "Wrong number of arguments to QOpenGLShaderProgramWrap::addShader()")
        .ThrowAsJavaScriptException();
  }

  Napi::Object shaderObject = info[0].As<Napi::Object>();
  QOpenGLShaderWrap* shaderWrap =
      Napi::ObjectWrap<QOpenGLShaderWrap>::Unwrap(shaderObject);
  QOpenGLShader* shader = shaderWrap->getInternalInstance();
  bool result = this->instance->addShader(shader);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::bind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->bind();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::link(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->link();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::attributeLocation(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  QString attribute =
      QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  auto result = this->instance->attributeLocation(attribute);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::release(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->release();
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::uniformLocation(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  QString uniform =
      QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  auto result = this->instance->attributeLocation(uniform);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::setUniformValue1i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLint value = info[1].As<Napi::Number>().Int32Value();
  this->instance->setUniformValue(location, value);
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::disableAttributeArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  this->instance->disableAttributeArray(location);
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::enableAttributeArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  this->instance->enableAttributeArray(location);
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::setUniformMatrix4fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLint location = info[0].As<Napi::Number>().Int32Value();
  auto arrayBuffer =
      info[1].As<Napi::ArrayBuffer>();  // Should be full of GLfloat
  QMatrix4x4 matrix(static_cast<GLfloat*>(arrayBuffer.Data()));
  this->instance->setUniformValue(location, matrix);
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::setAttributeBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLenum type = static_cast<GLenum>(info[1].As<Napi::Number>().Int32Value());
  int offset = info[2].As<Napi::Number>().Int32Value();
  int tupleSize = info[3].As<Napi::Number>().Int32Value();
  int stride = info[4].As<Napi::Number>().Int32Value();
  this->instance->setAttributeBuffer(location, type, offset, tupleSize, stride);
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::programId(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return Napi::Number::New(env, this->instance->programId());
}
