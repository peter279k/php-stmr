--TEST--
Check if stmr is loaded
--SKIPIF--
<?php
if (!extension_loaded('stmr')) {
	echo 'skip';
}
?>
--FILE--
<?php
if (extension_loaded('stmr')) {
    echo 'The extension "stmr" is available';
}
?>
--EXPECT--
The extension "stmr" is available
