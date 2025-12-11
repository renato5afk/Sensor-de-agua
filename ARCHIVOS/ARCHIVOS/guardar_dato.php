<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "iot";
$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
 die("Error de conexión: " . $conn->connect_error);
}
if (isset($_GET['valor'])) {
 $valor = $_GET['valor'];
 $sql = "INSERT INTO datos_iot (valor) VALUES ('$valor')";
 if ($conn->query($sql) === TRUE) {
 echo "Dato guardado correctamente";
 } else {
 echo "Error al guardar: " . $conn->error;
 }
} else {
 echo "No se recibió ningún dato";
}
$conn->close();
?>