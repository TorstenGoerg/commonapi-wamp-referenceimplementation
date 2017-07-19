/*******************************************************************************
* Copyright (c) 2017 itemis AG (http://www.itemis.de).
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*******************************************************************************/

// var autobahn = require('autobahn');

/*
var connection = new autobahn.Connection({
   transports: [
      {
         'type': 'websocket',
         'url': 'ws://localhost:8000/'
      }
   ],
    transports: [{
        type: 'rawsocket',
        port: 8000,
        host: 'localhost'
    }],
    realm: 'realm1'
});
*/

/*
         console.log("I am alive!");
         var connection = new autobahn.Connection({
            url: 'ws://127.0.0.1:8080/ws',
            realm: 'realm1'}
         );

         connection.onopen = function (session, details) {

            console.log("Connected", details);

            var cnt = 0;

            function on_topic1(args) {
               cnt += 1;
               console.log("Got " + cnt + "-th event on topic1:", args[0]);
            }
            session.subscribe('com.examples.subscriptions.topic1', on_topic1);

            var data = { a: 23, b: 66 };
            session.call('com.examples.calculator.add2', [23, 66]).then(
               function (res) {
                  console.log("Call succeeded. Result:", res);
               },
               function (err) {
                  console.log(err);
               }
            );
         };

         connection.onclose = function (reason, details) {
            console.log("Connection closed", reason, details);
         }

         connection.open();
*/

/*
    var connection = new autobahn.Connection({url: 'ws://127.0.0.1:8080/ws', realm: 'realm1'});
    connection.onopen = function (session, details) {

            console.log("Connected", details);

        // call a remote procedure
//        session.call('add2', [1, 11, 22]).then(
        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2', [1, 11, 22]).then(
//        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.play', [1]).then(
               function (res) {
                  console.log("Call succeeded. Result:", res);
                  console.log("sum:", res.args[0]);
                  console.log("diff:", res.args[1]);
               },
               function (err) {
                  console.log(err);
               }
        );
    };

         connection.onclose = function (reason, details) {
            console.log("Connection closed", reason, details);
         }

    connection.open();
*/


class Summands {
  constructor(left, right) {
    this.left = left;
    this.right = right;
  }
}

class Params {
  constructor(ss, x) {
    this.ss = ss;
    this.x = x;
  }
}

class SumDiff {
  constructor(sum, diff) {
    this.sum = sum;
    this.diff = diff;
  }
}



function initApp() {
	// connect UI buttons with RPC calls
	$("#m1").click(function() { play(); });
	$("#m2").click(function() { add2(); });
	$("#m3").click(function() { add2struct(); });
	$("#m4").click(function() { add2nestedStruct(); });
}


function play() {
    console.log("play()");

    var connection = new autobahn.Connection({url: 'ws://127.0.0.1:8080/ws', realm: 'realm1'});
    connection.onopen = function (session, details) {

        console.log("Connected", details);

        // call a remote procedure
        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.play', [1]).then(
            function (res) {
                console.log("Call succeeded. Result:", res);
            },
            function (err) {
                console.log(err);
            }
        );
    };

    connection.onclose = function (reason, details) {
        console.log("Connection closed", reason, details);
    }

    connection.open();
}

function add2() {
    console.log("add2()");

    var connection = new autobahn.Connection({url: 'ws://127.0.0.1:8080/ws', realm: 'realm1'});
    connection.onopen = function (session, details) {

        console.log("Connected", details);

        // call a remote procedure
//        session.call('add2', [1, 11, 22]).then(
        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2', [1, 11, 22]).then(
            function (res) {
                console.log("Call succeeded. Result:", res);
                console.log("sum:", res.args[0]);
                console.log("diff:", res.args[1]);
            },
            function (err) {
                console.log(err);
            }
        );
    };

    connection.onclose = function (reason, details) {
        console.log("Connection closed", reason, details);
    }

    connection.open();
}

function add2struct() {
    console.log("add2struct()");

    var connection = new autobahn.Connection({url: 'ws://127.0.0.1:8080/ws', realm: 'realm1'});
    connection.onopen = function (session, details) {

        console.log("Connected", details);

        // call a remote procedure
        var summands = new Summands(33,11);
        console.log("original object:", summands);
        var encoded = msgpack.pack(summands);
        var decoded = msgpack.unpack(encoded);
        console.log("decoded:", decoded);
        
        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2struct', [1, [summands.left, summands.right]]).then(
//        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2struct', [1, summands]).then(
//        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2struct', [1, [33, 11]]).then(
            function (res) {
                console.log("Call succeeded. Result:", res);
                console.log("sum:", res[0]);
                console.log("diff:", res[1]);
            },
            function (err) {
                console.log(err);
            }
        );
    };

    connection.onclose = function (reason, details) {
        console.log("Connection closed", reason, details);
    }

    connection.open();
}

function add2nestedStruct() {
    console.log("add2nestedStruct()");

    var connection = new autobahn.Connection({url: 'ws://127.0.0.1:8080/ws', realm: 'realm1'});
    connection.onopen = function (session, details) {

        console.log("Connected", details);

        // call a remote procedure
        session.call('local:example.ExampleInterface:commonapi.examples.HelloWorld.add2nestedStruct', [1, [[33, 11], 123]]).then(
            function (res) {
                console.log("Call succeeded. Result:", res);
                console.log("sum:", res[0]);
                console.log("diff:", res[1]);
            },
            function (err) {
                console.log(err);
            }
        );
    };

    connection.onclose = function (reason, details) {
        console.log("Connection closed", reason, details);
    }

    connection.open();
}
