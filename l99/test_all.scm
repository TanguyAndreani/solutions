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
        (exit))))

(define-syntax assert
  (syntax-rules ()
    ((_ name expr) (assert-helper name 'expr expr))))

(assert 'my-last-normal-list
  (equal? (my-last '(1 2 3 4))
          '(4)))
(assert 'my-last-single-element
  (equal? (my-last '(1))
          '(1)))
(assert 'my-last-empty-list
  (equal? (my-last '())
          'undefined))
(assert 'my-last-not-a-list
  (equal? (my-last 'hello)
          'undefined))


(assert 'my-but-last-normal-list
  (equal? (my-but-last '(1 2 3 4))
          '(4)))
(assert 'my-but-last-single-element
  (equal? (my-but-last '(1 2))
          '(1 2)))
(assert 'my-but-last-single-element
  (equal? (my-but-last '(1))
          'undefined))
(assert 'my-but-last-empty-list
  (equal? (my-but-last '())
          'undefined))
(assert 'my-but-last-not-a-list
  (equal? (my-but-last 'hello)
          'undefined))