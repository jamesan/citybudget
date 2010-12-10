// $Id$

(function ($) {
  var colours = new Array('#7F0000','#7F0F00','#7F1E00','#7F2D00','#7F3C00','#7F4B00','#7F5A00','#7F6900','#7F7800','#777F00','#687F00','#597F00','#4A7F00','#3B7F00','#2C7F00','#1D7F00','#0E7F00','#007F01','#007F10','#007F1F','#007F2E','#007F3D','#007F4C','#007F5B','#007F6A','#007F79','#00797F','#006A7F','#005B7F','#004C7F','#003D7F','#002E7F','#001F7F','#00107F','#00007F','#0E007F','#1D007F','#2C007F','#3B007F','#4A007F','#59007F','#68007F','#77007F','#7F0078','#7F0069','#7F005A','#7F004B','#7F003C','#7F002D','#7F001E','#7F000F','#7F0000');
  var coloursHighlight = new Array('#BF0000','#BF1600','#BF2D00','#BF4300','#BF5A00','#BF7000','#BF8700','#BF9E00','#BFB400','#B3BF00','#9CBF00','#86BF00','#6FBF00','#58BF00','#42BF00','#2BBF00','#15BF00','#00BF01','#00BF18','#00BF2E','#00BF45','#00BF5B','#00BF72','#00BF89','#00BF9F','#00BFB6','#00B6BF','#009FBF','#0089BF','#0072BF','#005BBF','#0045BF','#002EBF','#0018BF','#0001BF','#1500BF','#2B00BF','#4200BF','#5800BF','#6F00BF','#8600BF','#9C00BF','#B300BF','#BF00B4','#BF009E','#BF0087','#BF0070','#BF005A','#BF0043','#BF002D','#BF0016');

  var citybudgetapi = {
    'apiPath': '/api/citybudget'
  };

  citybudgetapi.retrieve = function (name, callback) {
    $.ajax({
      type: 'GET',
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
      citybudgetapi.treemapdata = {
        'keys': [],
        'children': [],
        'data': {
          '$color': '#444',
          'colour': '#444',
          'colourHighlight': '#888'
        },
        'id': 'root',
        'name': 'Operating Budgets'
      };
      for (var i in programs) {
        var programName = programs[i].name;
        var colour = colours.shift();
        var colourHighlight = coloursHighlight.shift();
        var childNode = {
          'children': [],
          'data': {
            '$area': programs[i]['2009 Budget'],
            '$color': colour,
            'colour': colour,
            'colourHighlight': colourHighlight
          },
          'id': programName,
          'name': programName
        };
        var counter = citybudgetapi.treemapdata.children.push(childNode) - 1;
        citybudgetapi.treemapdata.keys[programName] = counter;
        citybudgetapi.retrieve(programs[i].name, citybudget_js_add_child);
        citybudget_js_refresh(counter);
      }
      citybudget_js_treemap();
    });

    citybudget_js_add_child = function (program){
      var programName = program.name;
      var line_items = program.line_items;
      for (var name in line_items) {
        var counter = citybudgetapi.treemapdata.keys[programName];
        var id = name + '-' + counter;
        var childNode = {
          'children': [],
          'data': {
            '$area': line_items[name]['2009_budget'],
            '$color': '#444',
            'colour': '#444',
            'colourHighlight': '#888',
            '2009 Budget': line_items[name]['2009_budget'],
            '2009 Actual': line_items[name]['2009_actual'],
            '2010 Budget': line_items[name]['2010_budget'],
            '2011 Outlook': line_items[name]['2011_outlook'],
            '2012 Outlook': line_items[name]['2012_outlook']
          },
          'id': id,
          'name': name
        };
        citybudgetapi.treemapdata.children[counter].children.push(childNode);
      }
      citybudget_js_refresh();
    };

    citybudget_js_refresh = function (counter) {
      if(counter) {
        citybudget_js_refresh.total = counter;
        citybudget_js_refresh.counter = counter;
        $('#citybudget-js-treemap1').progressbar({
          value: 50
        });
      } else if(citybudget_js_refresh.counter === 0) {
        //$('#citybudget-js').text(JSON.stringify(citybudgetapi.treemapdata));
        citybudgetapi.treemap.loadJSON(citybudgetapi.treemapdata);
        citybudgetapi.treemap.refresh();
      } else {
        citybudget_js_refresh.counter--;
        var percentage = Math.floor(100 * (1 - citybudget_js_refresh.counter / citybudget_js_refresh.total));
        if(percentage != Number.NaN) {
          $('#citybudget-js-treemap1').progressbar(percentage);
        }
      }
    };

    citybudget_js_treemap = function () {
      citybudgetapi.treemap = new $jit.TM.Squarified({
        //where to inject the visualization
        injectInto: 'citybudget-js-treemap2',
        //show only one tree level
        levelsToShow: 1,
        //parent box title heights
        titleHeight: 20,
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
            if(node && node._depth == 1) {
              if (citybudgetapi.treemapdata.lastnode == node) {
                citybudgetapi.treemap.out();
              } else {
                citybudgetapi.treemapdata.lastnode = node;
                citybudgetapi.treemap.enter(node);
              }
            }
          },
          onRightClick: function() {
            citybudgetapi.treemap.out();
          },
          //change node styles and canvas styles
          //when hovering a node
          onMouseEnter: function(node, eventInfo) {
            if(node) {
              //add node selected styles and replot node
              //node.setCanvasStyle('shadowBlur', 7);
              node.setData('color', node.data.colourHighlight);
              citybudgetapi.treemap.fx.plotNode(node, citybudgetapi.treemap.canvas);
              citybudgetapi.treemap.labels.plotLabel(citybudgetapi.treemap.canvas, node);
            }
          },
          onMouseLeave: function(node) {
            if(node) {
              //node.removeCanvasStyle('shadowBlur');
              node.setData('color', node.data.colour);
              citybudgetapi.treemap.plot();
            }
          }
        },
        //duration of the animations
        duration: 1000,
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
            var html = '<div class="tip-title">' + node.name
              + '</div><div class="tip-text">';
            var data = node.data;
            if(data.$area) {
              html += '$' + Math.round(data.$area);
            }
            html += '</div>';
            tip.innerHTML =  html;
          }
        },
        //Add the name of the node in the corresponding label
        //This method is called once, on label creation and only for DOM labels.
        onCreateLabel: function(domElement, node){
            domElement.innerHTML = node.name;
        }
      });
      //citybudget_js_refresh();
    };
  });
}(jQuery));