<!DOCTYPE html>
<?php
    //This checks for propper login access
    if(!session_start()){header("Location: login.php");exit;}
	$username = empty($_SESSION['username']) ? '' : $_SESSION['username'];
	if (!$username) {header("Location: login.php");exit;}
?>
<html>
    <head>
    <title></title>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>       
        <link rel="stylesheet" type="text/css" href="stylesheet.css">
        <script defer src="javascript.js"></script>
    </head>    
    <body>
        <h1 id ="clockDisplay"></h1>
    </body>
</html>