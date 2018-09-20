<?php
// $servername = "localhost";
// $username = "root";
// $password = "root";
// $db_name = "mcqs";

// // Create connection
// $connection = new mysqli($servername, $username, $password,$db_name);
// mysqli_set_charset($connection,"utf8");
// // Check connection
// if ($connection->connect_error) {
//     die("Connection failed: " . $connection->connect_error);
// } 
// //echo "Connected successfully....";

// $query="SELECT * FROM questions";

// $questions_set =  mysqli_query($connection, $query);


// //Test if there is $course_set is ok using confirm_result_set function in "../includes/functions.php"



?>
<!DOCTYPE html>
<html lang="en">
<head>
  <title>MCQs: Insert Questions</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
  <h2>Question No:</h2>
  <form action="/index.php">
    <div class="form-group">
      <label for="text">Question topic</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>
    <div class="form-group">
      <label for="pwd">Question text:</label>
       <textarea class="form-control" rows="5" name="q_text"></textarea>
    </div>
    <div class="form-group">
      <label for="text">Answer 1</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>
    <div class="form-group">
      <label for="text">Answer 2</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>
    <div class="form-group">
      <label for="text">Answer 3</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>
    <div class="form-group">
      <label for="text">Answer 4</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>
    <div class="form-group">
      <label for="text">Answer 5</label>
      <input type="text" class="form-control"   name="q_topic">
    </div>


    <button type="submit" class="btn btn-default">Submit</button>


  </form>
</div>

</body>
</html>
