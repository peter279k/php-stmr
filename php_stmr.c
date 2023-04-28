/* stmr extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_stmr.h"
#include "stmr.h"

PHP_FUNCTION(stem)
{
    char *word = "word";
    size_t len = sizeof("word") - 1;
    int end = stem(word, 0, strlen(word) - 1);
    word[end + 1] = 0;

    ZEND_PARSE_PARAMETERS_START(0,1)
        Z_PARAM_OPTIONAL
	Z_PARAM_STRING(word, len);
    ZEND_PARSE_PARAMETERS_END();

    php_printf("%s!\r\n", word);
}

ZEND_BEGIN_ARG_INFO(arginfo_stem, 0)
    ZEND_ARG_INFO(0,str)
ZEND_END_ARG_INFO()

const zend_function_entry stem_functions[] = {
    PHP_FE(stem, arginfo_stem)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(stem)
{
    /* Here the module is being initialized */
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(stem)
{
    /* Here the module is deinitialized */
    return SUCCESS;
}

PHP_RINIT_FUNCTION(stem)
{
#if defined(ZTS) && defined(COMPILE_DL_STMR)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(stem)
{
    /* Here the module is deinitialized for a given request */
    return SUCCESS;
}

PHP_MINFO_FUNCTION(stem)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "stem support", "enabled");
    php_info_print_table_end();
}

zend_module_entry hello_module_entry = {
    STANDARD_MODULE_HEADER,
    "stmr", /* Extension name */
    stem_functions, /* zend_function_entry */
    PHP_MINIT(stem), /* PHP_MINIT - Module initialization */
    PHP_MSHUTDOWN(stem), /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(stem), /* PHP_RINIT - Request initialization */
    PHP_RSHUTDOWN(stem), /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(stem), /* PHP_MINFO - Module info */
    PHP_STMR_VERSION, /* Version */
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_STMR
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(stmr)
#endif
