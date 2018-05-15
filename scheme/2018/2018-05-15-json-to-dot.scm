(use gauche.sequence :prefix seq:)
(use rfc.json :prefix j:)

(define (json-label obj)
  (cond ((string? obj) (format "s:~S" obj))
        ((number? obj) (format "n:~D" obj))
        ((symbol? obj) (symbol->string obj))
        ((pair? obj) "dic")
        ((vector? obj) "arr")))

(define (json->dot oport id obj)
  (format oport "~a [label=~S];\n" id (json-label obj))
  (cond
   ((pair? obj)
    (seq:for-each-with-index (lambda (index pair)
                               (let ((child-id (format "~a_~D" id index)))
                                 (json->dot oport child-id (cdr pair))
                                 (format oport "~a -> ~a [label=~S];\n" id child-id (car pair))))
                             obj))
   ((vector? obj)
    (seq:for-each-with-index (lambda (index elem)
                               (let ((child-id (format "~a_~D" id index)))
                                 (json->dot oport child-id elem)
                                 (format oport "~a -> ~a [label=~S];\n" id child-id index)))
                             obj))
   (else #f)))


(define (main args)
  (let* ((filename (cadr args))
         (obj (with-input-from-file filename j:parse-json)))
    (print "digraph json {\n")
    (json->dot (standard-output-port) "input" obj)
    (print "}\n")))
