# RESERVED_WARNING
# Provide default versions for ports with multiple versions selectable
# by the user.
#
# Users who want to override these defaults can easily do so by defining
# DEFAULT_VERSIONS in their make.conf as follows:
#
# DEFAULT_VERSIONS=	perl5=5.36 ruby=3.2
#

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

.  for base in FIREBIRD LUA MYSQL PERL5 PHP PGSQL PYTHON3 RUBY SSL TCL
.undef ${base}_DEFAULT
.  endfor

.  for base in ${DEFAULT_VERSIONS}
_l=			${base:C/=.*//g}
${_l:tu}_DEFAULT=	${base:C/.*=//g}
.  endfor

#-------------------------------------------------------------------------
# PERL5
# Possible values: 5.34 and 5.36
#-------------------------------------------------------------------------

PERL5_DEFAULT?=		5.34

PERL_5.34_VERSION=	5.34.1
PERL_5.36_VERSION=	5.36.0

#-------------------------------------------------------------------------
# RUBY
# Possible values: 3.0, 3.1, 3.2
#-------------------------------------------------------------------------

RUBY_DEFAULT?=		3.1

RUBY_3.0_VERSION=	3.0.3
RUBY_3.1_VERSION=	3.1.3
RUBY_3.2_VERSION=	3.2.0

#-------------------------------------------------------------------------
# PYTHON
# Possible values: 3.10, 3.11
#-------------------------------------------------------------------------

PYTHON3_DEFAULT?=	3.10

PYTHON_3.10_VERSION=	3.10.9
PYTHON_3.11_VERSION=	3.11.1

#-------------------------------------------------------------------------
# SSL
# Possible values: openssl10, openssl11, openssl30, libressl, libressl-devel
#-------------------------------------------------------------------------

SSL_DEFAULT?=		libressl

#-------------------------------------------------------------------------
# LUA
# Possible values: 5.2, 5.3, 5.4
#-------------------------------------------------------------------------

LUA_DEFAULT?=		5.3

LUA_5.2_VERSION=	5.2.4
LUA_5.3_VERSION=	5.3.6
LUA_5.4_VERSION=	5.4.4

#-------------------------------------------------------------------------
# TCL/TK
# Possible values: 8.5, 8.6
#-------------------------------------------------------------------------

TCL_DEFAULT?=		8.6

TCL_8.5_VERSION=	8.5.19
TCL_8.6_VERSION=	8.6.13

#-------------------------------------------------------------------------
# PGSQL
# Possible values: 11, 12, 13, 14, 15
#-------------------------------------------------------------------------

PGSQL_DEFAULT?=		14

PGSQL_11_VERSION=	11.18
PGSQL_12_VERSION=	12.13
PGSQL_13_VERSION=	13.9
PGSQL_14_VERSION=	14.6
PGSQL_15_VERSION=	15.1

#-------------------------------------------------------------------------
# MYSQL and derivatives
# Possible values: oracle-(5.7,8.0), mariadb-(10.[3456789], 10.1[01]),
#                  percona-(5.5,5.6,5.7), galera-(5.5,5.6,5.7)
#
# MariaDB releases:
#   MariaDB 10.3   EOL 25 May 2023 (STABLE)
#   MariaDB 10.4   EOL 18 JUN 2024 (STABLE)
#   MariaDB 10.5   EOL 24 JUN 2025 (STABLE)
#   MariaDB 10.6   EOL 06 JUL 2026 (STABLE)
#   MariaDB 10.7   EOL 14 Feb 2023 (SHORT TERM)
#   MariaDB 10.8   EOL 20 May 2023 (SHORT TERM)
#   MariaDB 10.9   EOL 22 Aug 2023 (SHORT TERM)
#   MariaDB 10.10  CURRENT
#   MariaDB 10.11  DEVELOPMENT
#
#-------------------------------------------------------------------------

MYSQL_DEFAULT=			oracle-8.0

MYSQL_oracle-8.0_VERSION=	8.0.32
MYSQL_oracle-5.7_VERSION=	5.7.41
MYSQL_mariadb-10.3_VERSION=	10.3.37
MYSQL_mariadb-10.4_VERSION=	10.4.27
MYSQL_mariadb-10.5_VERSION=	10.5.18
MYSQL_mariadb-10.6_VERSION=	10.6.11
MYSQL_mariadb-10.7_VERSION=	10.7.7
MYSQL_mariadb-10.8_VERSION=	10.8.6
MYSQL_mariadb-10.9_VERSION=	10.9.4
MYSQL_mariadb-10.10_VERSION=	10.10.2
MYSQL_mariadb-10.11_VERSION=	10.11.1
MYSQL_percona-5.7_VERSION=	5.7.17
MYSQL_percona-5.6_VERSION=	5.6.35
MYSQL_percona-5.5_VERSION=	5.5.54

#-------------------------------------------------------------------------
# Firebird database server
# Possible values: 2.5, 3.0 (later 4.0)
#-------------------------------------------------------------------------

FIREBIRD_DEFAULT?=	2.5

FIREBIRD_2.5_VERSION=	2.5.9
FIREBIRD_3.0_VERSION=	3.0.7
FIREBIRD_4.0_VERSION=	4.0.2

#-------------------------------------------------------------------------
# PHP (restricted to branches still receiving updates)
# Possible values: 8.0, 8.1, 8.2
#-------------------------------------------------------------------------

PHP_DEFAULT?=		8.1

PHP_8.0_VERSION=	8.0.27
PHP_8.1_VERSION=	8.1.15
PHP_8.2_VERSION=	8.2.2

#-------------------------------------------------------------------------
# Ravenports system root versions per platform
# Format: ID=opsys/arch/stdarch/os-version/os-release/os-major
#-------------------------------------------------------------------------

PLATFORM_FreeBSD_x86-64=	FreeBSD/amd64/x86_64/1202000/12.2/12
PLATFORM_DragonFly_x86-64=	DragonFly/x86_64/x86_64/600200/6.2/6.2
PLATFORM_Linux_x86-64=		Linux/x86_64/x86_64/440053/4.4.0/4.4
PLATFORM_SunOS_x86-64=		SunOS/i86pc/x86_64/510200910/5.10/5.10
PLATFORM_MacOS_x86-64=		Darwin/x86_64/x86_64/170700/17.7.0/17
PLATFORM_NetBSD_x86-64=		NetBSD/x86_64/x86_64/902000000/9.2/9
PLATFORM_OpenBSD_x86-64=	OpenBSD/amd64/x86_64/tbd/tbd/tbd

.endif # defined (_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
