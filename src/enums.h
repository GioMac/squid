
/*
 * $Id: enums.h,v 1.232 2003/07/06 21:50:56 hno Exp $
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#ifndef SQUID_ENUMS_H
#define SQUID_ENUMS_H

typedef enum {
    LOG_TAG_NONE,
    LOG_TCP_HIT,
    LOG_TCP_MISS,
    LOG_TCP_REFRESH_HIT,
    LOG_TCP_REFRESH_FAIL_HIT,
    LOG_TCP_REFRESH_MISS,
    LOG_TCP_CLIENT_REFRESH_MISS,
    LOG_TCP_IMS_HIT,
    LOG_TCP_SWAPFAIL_MISS,
    LOG_TCP_NEGATIVE_HIT,
    LOG_TCP_MEM_HIT,
    LOG_TCP_DENIED,
    LOG_TCP_OFFLINE_HIT,
#if LOG_TCP_REDIRECTS
    LOG_TCP_REDIRECT,
#endif
    LOG_UDP_HIT,
    LOG_UDP_MISS,
    LOG_UDP_DENIED,
    LOG_UDP_INVALID,
    LOG_UDP_MISS_NOFETCH,
    LOG_ICP_QUERY,
    LOG_TYPE_MAX
} log_type;

typedef enum {
    ERR_NONE,
    ERR_READ_TIMEOUT,
    ERR_LIFETIME_EXP,
    ERR_READ_ERROR,
    ERR_WRITE_ERROR,
    ERR_SHUTTING_DOWN,
    ERR_CONNECT_FAIL,
    ERR_INVALID_REQ,
    ERR_UNSUP_REQ,
    ERR_INVALID_URL,
    ERR_SOCKET_FAILURE,
    ERR_DNS_FAIL,
    ERR_CANNOT_FORWARD,
    ERR_FORWARDING_DENIED,
    ERR_NO_RELAY,
    ERR_ZERO_SIZE_OBJECT,
    ERR_FTP_DISABLED,
    ERR_FTP_FAILURE,
    ERR_URN_RESOLVE,
    ERR_ACCESS_DENIED,
    ERR_CACHE_ACCESS_DENIED,
    ERR_CACHE_MGR_ACCESS_DENIED,
    ERR_SQUID_SIGNATURE,	/* not really an error */
    ERR_FTP_PUT_CREATED,	/* !error,a note that the file was created */
    ERR_FTP_PUT_MODIFIED,	/* modified, !created */
    ERR_FTP_PUT_ERROR,
    ERR_FTP_NOT_FOUND,
    ERR_FTP_FORBIDDEN,
    ERR_FTP_UNAVAILABLE,
    ERR_ONLY_IF_CACHED_MISS,	/* failure to satisfy only-if-cached request */
    ERR_TOO_BIG,
    TCP_RESET,
    ERR_ESI,                    /* Failure to perform ESI processing */
    ERR_MAX
} err_type;

enum fd_type {
    FD_NONE,
    FD_LOG,
    FD_FILE,
    FD_SOCKET,
    FD_PIPE,
    FD_UNKNOWN
};

enum {
    FD_READ,
    FD_WRITE
};

typedef enum {
    PEER_NONE,
    PEER_SIBLING,
    PEER_PARENT,
    PEER_MULTICAST
} peer_t;

typedef enum {
    LOOKUP_NONE,
    LOOKUP_HIT,
    LOOKUP_MISS
} lookup_t;

/* recognized or "known" header fields; @?@ add more! */
typedef enum {
    HDR_BAD_HDR = -1,
    HDR_ACCEPT = 0,
    HDR_ACCEPT_CHARSET,
    HDR_ACCEPT_ENCODING,
    HDR_ACCEPT_LANGUAGE,
    HDR_ACCEPT_RANGES,
    HDR_AGE,
    HDR_ALLOW,
    HDR_AUTHORIZATION,
    HDR_CACHE_CONTROL,
    HDR_CONNECTION,
    HDR_CONTENT_BASE,
    HDR_CONTENT_ENCODING,
    HDR_CONTENT_LANGUAGE,
    HDR_CONTENT_LENGTH,
    HDR_CONTENT_LOCATION,
    HDR_CONTENT_MD5,
    HDR_CONTENT_RANGE,
    HDR_CONTENT_TYPE,
    HDR_COOKIE,
    HDR_DATE,
    HDR_ETAG,
    HDR_EXPIRES,
    HDR_FROM,
    HDR_HOST,
    HDR_IF_MATCH,
    HDR_IF_MODIFIED_SINCE,
    HDR_IF_NONE_MATCH,
    HDR_IF_RANGE,
    HDR_LAST_MODIFIED,
    HDR_LINK,
    HDR_LOCATION,
    HDR_MAX_FORWARDS,
    HDR_MIME_VERSION,
    HDR_PRAGMA,
    HDR_PROXY_AUTHENTICATE,
    HDR_PROXY_AUTHENTICATION_INFO,
    HDR_PROXY_AUTHORIZATION,
    HDR_PROXY_CONNECTION,
    HDR_PUBLIC,
    HDR_RANGE,
    HDR_REQUEST_RANGE,		/* some clients use this, sigh */
    HDR_REFERER,
    HDR_RETRY_AFTER,
    HDR_SERVER,
    HDR_SET_COOKIE,
    HDR_TITLE,
    HDR_TRANSFER_ENCODING,
    HDR_UPGRADE,
    HDR_USER_AGENT,
    HDR_VARY,
    HDR_VIA,
    HDR_WARNING,
    HDR_WWW_AUTHENTICATE,
    HDR_AUTHENTICATION_INFO,
    HDR_X_CACHE,
    HDR_X_CACHE_LOOKUP,		/* tmp hack, remove later */
    HDR_X_FORWARDED_FOR,
    HDR_X_REQUEST_URI,		/* appended if ADD_X_REQUEST_URI is #defined */
    HDR_X_SQUID_ERROR,
    HDR_NEGOTIATE,
#if X_ACCELERATOR_VARY
    HDR_X_ACCELERATOR_VARY,
#endif
    HDR_SURROGATE_CAPABILITY,
    HDR_SURROGATE_CONTROL,
    HDR_FRONT_END_HTTPS,
    HDR_OTHER,
    HDR_ENUM_END
} http_hdr_type;

typedef enum {
    CC_BADHDR = -1,
    CC_PUBLIC = 0,
    CC_PRIVATE,
    CC_NO_CACHE,
    CC_NO_STORE,
    CC_NO_TRANSFORM,
    CC_MUST_REVALIDATE,
    CC_PROXY_REVALIDATE,
    CC_MAX_AGE,
    CC_S_MAXAGE,
    CC_MAX_STALE,
    CC_ONLY_IF_CACHED,
    CC_OTHER,
    CC_ENUM_END
} http_hdr_cc_type;

typedef enum {
    SC_NO_STORE,
    SC_NO_STORE_REMOTE,
    SC_MAX_AGE,
    SC_CONTENT,
    SC_OTHER,
    SC_ENUM_END
} http_hdr_sc_type;

/* possible types for http header fields */
typedef enum {
    ftInvalid = HDR_ENUM_END,	/* to catch nasty errors with hdr_id<->fld_type clashes */
    ftInt,
    ftStr,
    ftDate_1123,
    ftETag,
    ftPCc,
    ftPContRange,
    ftPRange,
    ftPSc,
    ftDate_1123_or_ETag
} field_type;

/* possible owners of http header */
typedef enum {
    hoNone,
#if USE_HTCP
    hoHtcpReply,
#endif
    hoRequest,
    hoReply
} http_hdr_owner_type;

typedef enum {
    HIER_NONE,
    DIRECT,
    SIBLING_HIT,
    PARENT_HIT,
    DEFAULT_PARENT,
    SINGLE_PARENT,
    FIRSTUP_PARENT,
    FIRST_PARENT_MISS,
    CLOSEST_PARENT_MISS,
    CLOSEST_PARENT,
    CLOSEST_DIRECT,
    NO_DIRECT_FAIL,
    SOURCE_FASTEST,
    ROUNDROBIN_PARENT,
#if USE_CACHE_DIGESTS
    CD_PARENT_HIT,
    CD_SIBLING_HIT,
#endif
#if USE_CARP
    CARP,
#endif
    ANY_OLD_PARENT,
    HIER_MAX
} hier_code;

typedef enum {
    ICP_INVALID,
    ICP_QUERY,
    ICP_HIT,
    ICP_MISS,
    ICP_ERR,
    ICP_SEND,
    ICP_SENDA,
    ICP_DATABEG,
    ICP_DATA,
    ICP_DATAEND,
    ICP_SECHO,
    ICP_DECHO,
    ICP_NOTIFY,
    ICP_INVALIDATE,
    ICP_DELETE,
    ICP_UNUSED15,
    ICP_UNUSED16,
    ICP_UNUSED17,
    ICP_UNUSED18,
    ICP_UNUSED19,
    ICP_UNUSED20,
    ICP_MISS_NOFETCH,
    ICP_DENIED,
    ICP_HIT_OBJ,
    ICP_END
} icp_opcode;

typedef enum _mem_status_t {
    NOT_IN_MEMORY,
    IN_MEMORY
} mem_status_t;

enum {
    PING_NONE,
    PING_WAITING,
    PING_DONE
};

enum {
    STORE_OK,
    STORE_PENDING
};

enum {
    SWAPOUT_NONE,
    SWAPOUT_WRITING,
    SWAPOUT_DONE
};

typedef enum {
    STORE_NON_CLIENT,
    STORE_MEM_CLIENT,
    STORE_DISK_CLIENT
} store_client_t;

typedef enum {
    METHOD_NONE,		/* 000 */
    METHOD_GET,			/* 001 */
    METHOD_POST,		/* 010 */
    METHOD_PUT,			/* 011 */
    METHOD_HEAD,		/* 100 */
    METHOD_CONNECT,		/* 101 */
    METHOD_TRACE,		/* 110 */
    METHOD_PURGE,		/* 111 */
    METHOD_OPTIONS,
    METHOD_DELETE,		/* RFC2616 section 9.7 */
    METHOD_PROPFIND,
    METHOD_PROPPATCH,
    METHOD_MKCOL,
    METHOD_COPY,
    METHOD_MOVE,
    METHOD_LOCK,
    METHOD_UNLOCK,
    METHOD_BMOVE,
    METHOD_BDELETE,
    METHOD_BPROPFIND,
    METHOD_BPROPPATCH,
    METHOD_BCOPY,
    METHOD_SEARCH,
    METHOD_SUBSCRIBE,
    METHOD_UNSUBSCRIBE,
    METHOD_POLL,
    METHOD_EXT00,
    METHOD_EXT01,
    METHOD_EXT02,
    METHOD_EXT03,
    METHOD_EXT04,
    METHOD_EXT05,
    METHOD_EXT06,
    METHOD_EXT07,
    METHOD_EXT08,
    METHOD_EXT09,
    METHOD_EXT10,
    METHOD_EXT11,
    METHOD_EXT12,
    METHOD_EXT13,
    METHOD_EXT14,
    METHOD_EXT15,
    METHOD_EXT16,
    METHOD_EXT17,
    METHOD_EXT18,
    METHOD_EXT19,
    METHOD_ENUM_END
} method_t;

typedef enum {
    PROTO_NONE,
    PROTO_HTTP,
    PROTO_FTP,
    PROTO_GOPHER,
    PROTO_WAIS,
    PROTO_CACHEOBJ,
    PROTO_ICP,
#if USE_HTCP
    PROTO_HTCP,
#endif
    PROTO_URN,
    PROTO_WHOIS,
    PROTO_INTERNAL,
    PROTO_HTTPS,
    PROTO_MAX
} protocol_t;

typedef enum {
    HTTP_STATUS_NONE = 0,
    HTTP_CONTINUE = 100,
    HTTP_SWITCHING_PROTOCOLS = 101,
    HTTP_PROCESSING = 102,	/* RFC2518 section 10.1 */
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_ACCEPTED = 202,
    HTTP_NON_AUTHORITATIVE_INFORMATION = 203,
    HTTP_NO_CONTENT = 204,
    HTTP_RESET_CONTENT = 205,
    HTTP_PARTIAL_CONTENT = 206,
    HTTP_MULTI_STATUS = 207,	/* RFC2518 section 10.2 */
    HTTP_MULTIPLE_CHOICES = 300,
    HTTP_MOVED_PERMANENTLY = 301,
    HTTP_MOVED_TEMPORARILY = 302,
    HTTP_SEE_OTHER = 303,
    HTTP_NOT_MODIFIED = 304,
    HTTP_USE_PROXY = 305,
    HTTP_TEMPORARY_REDIRECT = 307,
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_PAYMENT_REQUIRED = 402,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_METHOD_NOT_ALLOWED = 405,
    HTTP_NOT_ACCEPTABLE = 406,
    HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
    HTTP_REQUEST_TIMEOUT = 408,
    HTTP_CONFLICT = 409,
    HTTP_GONE = 410,
    HTTP_LENGTH_REQUIRED = 411,
    HTTP_PRECONDITION_FAILED = 412,
    HTTP_REQUEST_ENTITY_TOO_LARGE = 413,
    HTTP_REQUEST_URI_TOO_LARGE = 414,
    HTTP_UNSUPPORTED_MEDIA_TYPE = 415,
    HTTP_UNPROCESSABLE_ENTITY = 422,	/* RFC2518 section 10.3 */
    HTTP_LOCKED = 423,		/* RFC2518 section 10.4 */
    HTTP_FAILED_DEPENDENCY = 424,	/* RFC2518 section 10.5 */
    HTTP_INTERNAL_SERVER_ERROR = 500,
    HTTP_NOT_IMPLEMENTED = 501,
    HTTP_BAD_GATEWAY = 502,
    HTTP_SERVICE_UNAVAILABLE = 503,
    HTTP_GATEWAY_TIMEOUT = 504,
    HTTP_HTTP_VERSION_NOT_SUPPORTED = 505,
    HTTP_INSUFFICIENT_STORAGE = 507,	/* RFC2518 section 10.6 */
    HTTP_INVALID_HEADER = 600	/* Squid header parsing error */
} http_status;

/*
 * These are for StoreEntry->flag, which is defined as a SHORT
 *
 * NOTE: These flags are written to swap.state, so think very carefully
 * about deleting or re-assigning!
 */
enum {
    ENTRY_SPECIAL,
    ENTRY_REVALIDATE,
    DELAY_SENDING,
    RELEASE_REQUEST,
    REFRESH_REQUEST,
    ENTRY_CACHABLE,
    ENTRY_DISPATCHED,
    KEY_PRIVATE,
    ENTRY_FWD_HDR_WAIT,
    ENTRY_NEGCACHED,
    ENTRY_VALIDATED,
    ENTRY_BAD_LENGTH,
    ENTRY_ABORTED
#if UNUSED_CODE
    ENTRY_DONT_LOG
#endif
};

/*
 * These are for client Streams. Each node in the stream can be queried for
 * its status
 */
typedef enum {
    STREAM_NONE,		/* No particular status */
    STREAM_COMPLETE,		/* All data has been flushed, no more reads allowed */
    /* an unpredicted end has occured, no more
     * reads occured, but no need to tell 
     * downstream that an error occured
     */
    STREAM_UNPLANNED_COMPLETE,
    /* An error has occured in this node or an above one,
     * and the node is not generating an error body / it's
     * midstream
     */
    STREAM_FAILED
} clientStream_status_t;

typedef enum {
    ACCESS_DENIED,
    ACCESS_ALLOWED,
    ACCESS_REQ_PROXY_AUTH
} allow_t;

typedef enum {
    AUTH_ACL_CHALLENGE = -2,
    AUTH_ACL_HELPER = -1,
    AUTH_ACL_CANNOT_AUTHENTICATE = 0,
    AUTH_AUTHENTICATED = 1
} auth_acl_t;

typedef enum {
    AUTH_UNKNOWN,		/* default */
    AUTH_BASIC,
    AUTH_NTLM,
    AUTH_DIGEST,
    AUTH_BROKEN			/* known type, but broken data */
} auth_type_t;

/* stateful helper callback response codes */
typedef enum {
    S_HELPER_UNKNOWN,
    S_HELPER_RESERVE,
    S_HELPER_RELEASE,
    S_HELPER_DEFER
} stateful_helper_callback_t;

/* stateful helper reservation info */
typedef enum {
    S_HELPER_FREE,		/* available for requests */
    S_HELPER_RESERVED,		/* in a reserved state - no active request, but state data in the helper shouldn't be disturbed */
    S_HELPER_DEFERRED		/* available for requests, and at least one more will come from a previous caller with the server pointer */
} stateful_helper_reserve_t;


#if SQUID_SNMP
enum {
    SNMP_C_VIEW,
    SNMP_C_USER,
    SNMP_C_COMMUNITY
};

#endif

typedef enum {
    MEM_NONE,
    MEM_2K_BUF,
    MEM_4K_BUF,
    MEM_8K_BUF,
    MEM_16K_BUF,
    MEM_32K_BUF,
    MEM_64K_BUF,
    MEM_ACL_DENY_INFO_LIST,
    MEM_ACL_NAME_LIST,
    MEM_ACL_PROXY_AUTH_MATCH,
#if USE_CACHE_DIGESTS
    MEM_CACHE_DIGEST,
#endif
    MEM_CLIENT_INFO,
    MEM_LINK_LIST,
    MEM_DLINK_NODE,
    MEM_DONTFREE,
    MEM_DREAD_CTRL,
    MEM_DWRITE_Q,
    MEM_FQDNCACHE_ENTRY,
    MEM_FWD_SERVER,
    MEM_HELPER_REQUEST,
    MEM_HELPER_STATEFUL_REQUEST,
    MEM_HTTP_HDR_CC,
    MEM_HTTP_HDR_CONTENT_RANGE,
    MEM_HTTP_HDR_SC,
    MEM_HTTP_HDR_SCTARGET,
    MEM_IPCACHE_ENTRY,
    MEM_MD5_DIGEST,
    MEM_NETDBENTRY,
    MEM_NET_DB_NAME,
    MEM_RELIST,
    MEM_REQUEST_T,
    MEM_WORDLIST,
#if !USE_DNSSERVERS
    MEM_IDNS_QUERY,
#endif
    MEM_EVENT,
    MEM_SWAP_LOG_DATA,
    MEM_MAX
} mem_type;

/*
 * NOTE!  We must preserve the order of this list!
 */
enum {
    STORE_META_VOID,		/* should not come up */
    STORE_META_KEY_URL,		/* key w/ keytype */
    STORE_META_KEY_SHA,
    STORE_META_KEY_MD5,
    STORE_META_URL,		/* the url , if not in the header */
    STORE_META_STD,		/* standard metadata */
    STORE_META_HITMETERING,	/* reserved for hit metering */
    STORE_META_VALID,
    STORE_META_VARY_HEADERS,	/* Stores Vary request headers */
    STORE_META_END
};

enum {
    STORE_LOG_CREATE,
    STORE_LOG_SWAPIN,
    STORE_LOG_SWAPOUT,
    STORE_LOG_RELEASE,
    STORE_LOG_SWAPOUTFAIL
};

typedef enum {
    SWAP_LOG_NOP,
    SWAP_LOG_ADD,
    SWAP_LOG_DEL,
    SWAP_LOG_MAX
} swap_log_op;


/* parse state of HttpReply or HttpRequest */
typedef enum {
    psReadyToParseStartLine = 0,
    psReadyToParseHeaders,
    psParsed,
    psError
} HttpMsgParseState;


enum {
    MEDIAN_HTTP,
    MEDIAN_ICP_QUERY,
    MEDIAN_DNS,
    MEDIAN_HIT,
    MEDIAN_MISS,
    MEDIAN_NM,
    MEDIAN_NH,
    MEDIAN_ICP_REPLY
};

enum {
    SENT,
    RECV
};

/*
 * These are field indicators for raw cache-cache netdb transfers
 */
enum {
    NETDB_EX_NONE,
    NETDB_EX_NETWORK,
    NETDB_EX_RTT,
    NETDB_EX_HOPS
};

/*
 * cbdata types. similar to the MEM_* types above, but managed
 * in cbdata.c. A big difference is that these types are dynamically
 * allocated. This list is only a list of predefined types. Other types
 * are added runtime
 */
typedef enum {
    CBDATA_UNKNOWN = 0,
    CBDATA_UNDEF = 0,
    CBDATA_acl_access,
    CBDATA_ConnStateData,
    CBDATA_ErrorState,
    CBDATA_FwdState,
    CBDATA_generic_cbdata,
    CBDATA_helper,
    CBDATA_helper_server,
    CBDATA_statefulhelper,
    CBDATA_helper_stateful_server,
    CBDATA_peer,
    CBDATA_ps_state,
    CBDATA_RemovalPolicy,
    CBDATA_RemovalPolicyWalker,
    CBDATA_RemovalPurgeWalker,
    CBDATA_FIRST_CUSTOM_TYPE = 1000
} cbdata_type;

/*
 * Return codes from checkVary(request)
 */
enum {
    VARY_NONE,
    VARY_MATCH,
    VARY_OTHER,
    VARY_CANCEL
};

/*
 * Store digest state enum
 */
typedef enum {
    DIGEST_READ_NONE,
    DIGEST_READ_REPLY,
    DIGEST_READ_HEADERS,
    DIGEST_READ_CBLOCK,
    DIGEST_READ_MASK,
    DIGEST_READ_DONE
} digest_read_state_t;

typedef enum {
    COMM_OK = 0,
    COMM_ERROR = -1,
    COMM_NOMESSAGE = -3,
    COMM_TIMEOUT = -4,
    COMM_SHUTDOWN = -5,
    COMM_INPROGRESS = -6,
    COMM_ERR_CONNECT = -7,
    COMM_ERR_DNS = -8,
    COMM_ERR_CLOSING = -9
} comm_err_t;


/* CygWin & Windows NT Port */
#ifdef _SQUID_WIN32_
/*
 * Supported Windows OS types codes
 */
enum {
    _WIN_OS_UNKNOWN,
    _WIN_OS_WIN32S,
    _WIN_OS_WIN95,
    _WIN_OS_WIN98,
    _WIN_OS_WINME,
    _WIN_OS_WINNT,
    _WIN_OS_WIN2K,
    _WIN_OS_WINXP,
    _WIN_OS_WINNET
};

#endif

typedef enum {
    CLF_UNKNOWN,
    CLF_AUTO,
    CLF_CUSTOM,
    CLF_SQUID,
    CLF_COMMON,
    CLF_NONE
} customlog_type;

#endif /* SQUID_ENUMS_H */
