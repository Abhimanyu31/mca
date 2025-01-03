<!DOCTYPE html>
<html lang="en">
<head>
    <title>Factorial</title>
</head>
<body>
    <center>
        <form action="" method="POST">
            <fieldset style="width: 300px; height: 110px;">
            <legend>Factorial</legend><br>
            <input type="text" name="num" placeholder="Enter the number" required><br><br>
            <input type="submit" value="Find Factorial" name="submit"><br>
            </fieldset>
        </form>

        <?php
        if (isset($_POST['submit'])) {
            $n = $_POST['num'];

            function factorial($x) {
                if ($x == 0) {
                    return 1;
                }
                return $x * factorial($x - 1);
            }
            echo"<br>";
            echo "Factorial of $n is " . factorial($n);
        }
        ?>
    </center>
</body>
</html>