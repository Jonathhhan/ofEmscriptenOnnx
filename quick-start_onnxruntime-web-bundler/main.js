// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

const ort = require('onnxruntime-web');
var onnxSession;

startOnnxSession = function() {
	// create a new session and load the specific model.
	ort.InferenceSession.create("onnx/model.onnx", {executionProviders: ["wasm"] }).then((session) => {
		onnxSession = session;
		Module.onnx("status", "dummy");
	});
}

onnxInference = function() {
        // the model in this example contains a single MatMul node
        // it has 2 inputs: 'a'(float32, 3x4) and 'b'(float32, 4x3)
        // it has 1 output: 'c'(float32, 3x3)

	// prepare inputs. a tensor need its corresponding TypedArray as data
	const dataA = Float32Array.from([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);
	const dataB = Float32Array.from([10, 20, 30, 40, 50, Math.floor(Math.random() * 60), 70, 80, Math.floor(Math.random() * 90), 100, 110, Math.floor(Math.random() * 120)]);
	const tensorA = new ort.Tensor("float32", dataA, [3, 4]);
	const tensorB = new ort.Tensor("float32", dataB, [4, 3]);

	// prepare feeds. use model input names as keys.
	const feeds = { a: tensorA, b: tensorB };

	// feed inputs and run
	onnxSession.run(feeds).then((results) => {

		// read from results
		const dataC = results.c.data;
		console.log(`Data of result tensor 'c': ${dataC}`);
		Module.onnx("inference", `Data of result tensor 'c': ${dataC}`);
	});
}
