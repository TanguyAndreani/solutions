(load "lib/all.scm")

(define space!
  (lambda ()
    (display " ")))

(define (assert-helper name quoted-expr expr)
  (if expr
      (begin
        (display name)
        (space!)
        (display 'passed)
        (newline))
      (begin
        (display name)
        (space!)
        (display 'failed)
        (newline)
        (display quoted-expr)
        (newline)
        (if (eq? (car quoted-expr) 'equal?)
            (begin
              (display "Got")
              (space!)
              (display (eval (cadr quoted-expr) (interaction-environment)))
              (newline)
              (display "Expected")
              (space!)
              (display (eval (caddr quoted-expr) (interaction-environment))))))))

(define-syntax assert
  (syntax-rules ()
    ((_ name expr) (assert-helper name 'expr expr))))

(assert 'my-last-normal-list
        (equal? (my-last '(1 2 3 4))
                '(4)))

(assert 'my-last-single-element
        (equal? (my-last '(1))
                '(1)))

(assert 'my-but-last-normal-list
        (equal? (my-but-last '(1 2 3 4))
                '(4)))

(assert 'my-but-last-single-element
        (equal? (my-but-last '(1 2))
                '(1 2)))

(assert 'element-at-element-exit
        (equal? (element-at '(4 3 2 1) 3)
                2))

(assert 'my-reverse-simple
        (equal? (my-reverse '(tanguy is name my world hello))
                '(hello world my name is tanguy)))

(assert 'is-palindrom-yes
        (is-palindrom '(a b b a)))

(assert 'is-palindrom-no
        (not (is-palindrom '(a b b b))))

(assert 'my-flatten-problem-example
        (equal? (my-flatten '(a (b (c d) e)))
                '(a b c d e)))

(assert 'my-flatten-problem-example
        (equal? (my-flatten '(((a b c d))))
                '(a b c d)))

(assert 'compress-problem-example
        (equal? (compress '(a a a a b c c a a d e e e e))
                '(a b c a d e)))
