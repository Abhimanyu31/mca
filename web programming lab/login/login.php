<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login page</title>
</head>
<body>
<body><center>
    <h1>Student Login</h1>
    <form action="" method="POST">
        <label for="name">Enter your username: </label><input type="text" name="username"> <br><br>
        <label for="name">Enter your password: </label><input type="password" name="pword"> <br><br>
        <input type="submit" name='login'>
    </form><br>
    <a href="register.php"><button>Register</button></a>
    </center>
</body>
<?php
    if(isset($_POST['login'])){
        $username=$_POST['username'];
        $pword=$_POST['pword'];
        $conn=mysqli_connect('localhost','root','','student');
        if(!$conn){
            echo "connection error";
        }
        else{
            session_start();
            $query="SELECT * FROM student_details WHERE username='$username' AND password='$pword';" ;
            $q=mysqli_query($conn,$query);
            if($q){
                if (mysqli_num_rows($q) > 0) {
                    $row = mysqli_fetch_assoc($q);
                
                    $name = $row['name'];      
                    $roll_no = $row['rollno'];      
                    $username = $row['username'];        
                    $phno = $row['phno'];
                    $_SESSION['name']=$name;
                    header("Location: welcome.php");
                    exit();
                }
                else {
                    echo "Enter valid username!";
                }
            }
            else{
                echo "failed";
            }
        }
    }
?>
</html>