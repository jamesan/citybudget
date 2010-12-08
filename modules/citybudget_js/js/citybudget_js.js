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
        citybudget_append(programs[i]);
      }
      var tm = new $jit.TM.Squarified({
        injectInto: 'citybudget-js-treemap',
        animate: true,
      });
      tm.loadJSON(treemap);
      tm.refresh();
    });

    citybudget_append = function (programData) {
      var location = this.location.href + '/';
      $('<li class="program">' +
        '<a href="' + location + programData.name + '">' + programData.name +
        '</a> ' + programData['2009 Budget'] +
        '</li>').appendTo('#citybudget-js');
    };

    
  });
}(jQuery));