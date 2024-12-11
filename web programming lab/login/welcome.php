<?php
session_start();

if (isset($_SESSION['name'])) {
    $name = $_SESSION['name']; 
} else {
    $name = "Guest";  
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome Page</title>
</head>
<body>
    <h1>Welcome, <?php echo htmlspecialchars($name); ?>!</h1>
    <a href="logout.php"><button>Logout</button></a>

    <form method="POST" action="welcome.php">
    </form>
</body>
</html>