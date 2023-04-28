--TEST--
stem() test without parameters
--SKIPIF--
<?php
if (!extension_loaded('stmr')) {
	echo 'skip';
}
?>
--FILE--
<?php
stem();
?>
--EXPECT--
world
