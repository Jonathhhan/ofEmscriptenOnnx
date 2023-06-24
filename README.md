# ofEmscriptenOnnx

Run Onnx models with Open Frameworks and Emscripten
https://onnxruntime.ai/docs/


The template "quick-start_onnxruntime-web-bundler" is basically this example: https://github.com/microsoft/onnxruntime-inference-examples/tree/main/js/quick-start_onnxruntime-web-bundler

Edit main.js for customising inference or changing the model.

1. npm install onnxruntime-web
2. cd to folder "quick-start_onnxruntime-web-bundler".
2. npm i
3. npx webpack
4. Copy the generated "bundle.min.js" and "ort-wasm-simd-threaded.wasm" from the generated onnx folder into the OF apps "onnx" folder (there should also be the .onnx model).
5. Copy "html template.html" into "openFrameworks/libs/openFrameworksCompiled/project/emscripten".
6. Compile the Open Frameworks app with Emscripten.
