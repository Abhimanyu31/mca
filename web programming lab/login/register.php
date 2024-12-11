<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student register</title>
</head>
<body><center>
    <h1>Student Register</h1>
    <form action="" method="POST">
        <label for="name">Enter your name: </label><input type="text" name="name"> <br><br>
        <label for="name">Enter your email address: </label><input type="text" name="email"> <br><br>
        <label for="name">Enter your phone number: </label><input type="number" name="phno"> <br><br>
        <label for="name">Enter your password: </label><input type="password" name="pword"> <br><br>
        <label for="name">Please re-enter your password: </label><input type="password" name="repword"> <br><br>
        <input type="submit" name='Register'><br><br>
    </form>

    <a href="login.php"><button>Login</button></a>
</center>
    <?php
    if(isset($_POST['Register'])){
    if($_POST['pword']!=$_POST['repword']){
        echo "password mismatch";
    }
    else{
        $name=$_POST['name'];
        $username=$_POST['email'];
        $phno=$_POST['phno'];
        $pword=$_POST['pword'];
        $conn=mysqli_connect('localhost','root','','student');
        if(!$conn){
            echo "connection error";
        }
        else{
            $query="INSERT INTO student_details (name,username,phno,password) VALUES ('$name','$username','$phno','$pword');";
            $q=mysqli_query($conn,$query);
        }
        if($q){
            echo "successfully inserted";
        }
        else{
            echo "insertion failed";
        }
    }
}
?>
</body>

</html>
