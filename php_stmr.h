/* stmr extension for PHP */

#ifndef PHP_STMR_H
# define PHP_STMR_H

extern zend_module_entry stmr_module_entry;
# define phpext_stmr_ptr &stmr_module_entry

# define PHP_STMR_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_STMR)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_STMR_H */
