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
        (newline))))

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