var j5 = require('johnny-five')
var board = new j5.Board();

board.on('ready', function() {
  var red       = new j5.Led(12);
  var yellow    = new j5.Led(11);
  var green     = new j5.Led(10);
  var f_red     = new j5.Led(9);
  var f_green   = new j5.Led(8);
  var button    = new j5.Button(2);

  green.on();
  f_red.on();

  button.on("press", function() {

   green.off()
   yellow.on()

   setTimeout(function() {
    green.off();
    red.on();

    setTimeout(function() {
      f_red.off();
      f_green.on();

      setTimeout(function() {
        f_green.off();
        f_red.on();

        setTimeout(function() {
          yellow.on();

          setTimeout(function() {
            red.off();
            yellow.off();
            green.on();

            setTimeout(function() {
              return
            }, 2000);
          }, 600);
        }, 600);
      }, 2000);
     }, 600);
   }, 600);

  });
});