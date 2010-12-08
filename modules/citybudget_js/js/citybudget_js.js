// $Id$

(function ($) {
  var citybudgetapi = {
    'apiPath': '/api/citybudget'
  };

  citybudgetapi.retrieve = function (name, callback) {
    $.ajax({
      type: "GET",
      url: this.apiPath + '/' + name,
      dataType: 'json',
      success: callback
    });
  };

  citybudgetapi.index = function (callback) {
    $.getJSON(this.apiPath, callback);
  };

  $(document).ready(function () {
    citybudgetapi.index(function (programs) {
      var treemap = new Object();
      treemap.id = 'ID';
      treemap.name = 'Name';
      treemap.children = new Array();
      for (var i in programs) {
        var child = '{' +
          '"children": [],' +
          '"data": {' +
            '"$area": ' + programs[i]['2009 Budget'] + ',' +
          '},' +
          '"id": "' + programs[i].name + '",' +
          '"name": "' + programs[i].name + '",' +
        '}';
        var childNode = eval('(' + child + ')');
        treemap.children.push(childNode);
        //citybudget_append(programs[i]);
      }
      citybudget_js_treemap(treemap);
    });
    
    citybudget_js_treemap = function (treemap) {
      var tm = new $jit.TM.Squarified({
        //where to inject the visualization
        injectInto: 'citybudget-js-treemap',
        //show only one tree level
        levelsToShow: 1,
        //parent box title heights
        titleHeight: 0,
        //enable animations
        animate: true,
        //box offsets
        offset: 1,
        //use canvas text
        Label: {
          type: 'Native',
          size: 9,
          family: 'Tahoma, Verdana, Arial'
        },
        //enable specific canvas styles
        //when rendering nodes
        Node: {
          CanvasStyles: {
            shadowBlur: 0,
            shadowColor: '#000'
          }
        },
        //Attach left and right click events
        Events: {
          enable: true,
          onClick: function(node) {
            if(node) tm.enter(node);
          },
          onRightClick: function() {
            tm.out();
          },
          //change node styles and canvas styles
          //when hovering a node
          onMouseEnter: function(node, eventInfo) {
            if(node) {
              //add node selected styles and replot node
              node.setCanvasStyle('shadowBlur', 7);
              node.setData('color', '#888');
              tm.fx.plotNode(node, tm.canvas);
              tm.labels.plotLabel(tm.canvas, node);
            }
          },
          onMouseLeave: function(node) {
            if(node) {
              node.removeData('color');
              node.removeCanvasStyle('shadowBlur');
              tm.plot();
            }
          }
        },
        //Enable tips
        Tips: {
          enable: true,
          type: 'Native',
          //add positioning offsets
          offsetX: 20,
          offsetY: 20,
          //implement the onShow method to
          //add content to the tooltip when a node
          //is hovered
          onShow: function(tip, node, isLeaf, domElement) {
            var html = "<div class=\"tip-title\">" + node.name
              + "</div><div class=\"tip-text\">";
            var data = node.data;
            if(data.artist) {
              html += "Artist: " + data.artist + "<br />";
            }
            if(data.playcount) {
              html += "Play count: " + data.playcount;
            }
            if(data.image) {
              html += "<img src=\""+ data.image +"\" class=\"album\" />";
            }
            tip.innerHTML =  html;
          }
        },
      });
      tm.loadJSON(treemap);
      tm.refresh();
    };

    citybudget_append = function (programData) {
      var location = this.location.href + '/';
      $('<li class="program">' +
        '<a href="' + location + programData.name + '">' + programData.name +
        '</a> ' + programData['2009 Budget'] +
        '</li>').appendTo('#citybudget-js');
    };


  });
}(jQuery));