var j5 = require('johnny-five')
var board = new j5.Board();

board.on('ready', function() {
  var led1 = new j5.Led(11);
  var led2 = new j5.Led(12);

  led1.blink(500);
  led2.blink(100);

  setTimeout(function() {
    led1.stop().off()
    led2.stop().off()
  }, 5000);
});