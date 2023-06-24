# ofEmscriptenOnnx

Run Onnx models with Open Frameworks and Emscripten
https://onnxruntime.ai/docs/


The template "quick-start_onnxruntime-web-bundler" is basically this example: https://github.com/microsoft/onnxruntime-inference-examples/tree/main/js/quick-start_onnxruntime-web-bundler
Edit main.js for costomising or changing the model.
1. npm install onnxruntime-web
2. cd to folder "quick-start_onnxruntime-web-bundler".
2. npm i
3. npx webpack
4. copy the generated "bundle.min.js" and "ort-wasm-simd-threaded.wasm" into the apps "onnx" folder (there should also be the .onnx model).
5. copy "html template.html" into "openFrameworks/libs/openFrameworksCompiled/project/emscripten".
6. compile the Open Frameworks app with Emscripten.
