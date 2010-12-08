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

  // Drupal.note.create({
  //   subject: 'Note',
  //   note: 'A test note',
  // }, function(r) {console.log(r)});

  $(document).ready(function () {
    citybudgetapi.index(function (programs) {
      for (var i in programs) {
        citybudget_append(programs[i].name);
      }
    });

    citybudget_append = function (programName) {
      var programNode;

      programNode = $('<li class="program"><a href="' + this.location.href + '/' + programName + '">' +
                       programName + '</a></li>');
      programNode.appendTo('#citybudget-js');
    };


  /*
    var subject, text, list, note, note_saved, note_append;

    $('<div id="notetaking"><form>' +
        '<div class="subject-wrapper"><label for="note-subject">Subject</label></div>' +
        '<div class="note-wrapper"></div>' + 
        '<input class="cancel" type="submit" value="Cancel" />' +
        '<input class="save" type="submit" value="Save" />' +
      '</form></div>').appendTo('#citybudget-js');
    subject = $('<input class="subject" type="text" />').appendTo('#notetaking .subject-wrapper');
    text = $('<textarea class="note" cols="20" rows="5" />').appendTo('#notetaking .note-wrapper');
    list = $('<ul></ul>').appendTo('#notetaking');

    // Stop the form from submitting
    $('#notetaking form').submit(function () {
      return false;
    });

    $('#notetaking input.cancel').hide().click(function () {
      note = null;
      $(this).hide();
      $(subject).val('');
      $(text).val('');
    });

    $('#notetaking input.save').click(function () {
      var data;
      $(this).hide();
      $('#notetaking input.cancel').hide();

      data = {
        subject: $(subject).val(),
        note: $(text).val()
      };

      if (note) {
        data.id = note.id;
        note = null;
        noteapi.update(data, note_saved);
      }
      else {
        noteapi.create(data, note_saved);
      }
      note = null;
    });

    note_saved = function (res) {
      note = null;
      $(subject).val('');
      $(text).val('');
      $('#notetaking input.save').show();

      noteapi.retreive(res.id, function (res) {
        note_append(res);
      });
    };
*/
  });
}(jQuery));