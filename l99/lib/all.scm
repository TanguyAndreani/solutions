;(*) Find the last box of a list.
;    Example:
;    * (my-last '(a b c d))
;    (D)
(define (my-last ls)
  (if (null? (cdr ls))
      ls
      (my-last (cdr ls))))

;(*) Find the last but one box of a list.
;    Example:
;    * (my-but-last '(a b c d))
;    (C D)
(define (my-but-last ls)
  (if (null? (cddr ls))
      ls
      (my-last (cdr ls))))

;(*) Find the K'th element of a list.
;    The first element in the list is number 1.
;    Example:
;    * (element-at '(a b c d e) 3)
;    C
(define (element-at ls n)
  (if (zero? (- n 1))
      (car ls)
      (element-at (cdr ls) (- n 1))))

;(*) Find the number of elements of a list.
(define (my-length ls)
  (if (null? ls)
      0
      (+ 1 (my-length (cdr ls)))))

;(*) Reverse a list
(define (my-reverse ls)
  (if (null? ls)
      '()
      (append (my-reverse (cdr ls)) (list (car ls)))))

;(*) Find out whether a list is a palindrome.
;    A palindrome can be read forward or backward; e.g. (x a m a x).
(define (is-palindrom ls)
  (equal? (my-reverse ls) ls))

;(**) Flatten a nested list structure.
;     Transform a list, possibly holding lists as elements into a `flat' list by replacing each list with its elements (recursively).
;
;     Example:
;     * (my-flatten '(a (b (c d) e)))
;     (A B C D E)
;
;     Hint: Use the predefined functions list and append.
(define (my-flatten ls)
  (cond
    ((null? ls) '())
    ((list? (car ls))
     (append (my-flatten (car ls))
             (my-flatten (cdr ls))))
    (else
     (cons (car ls)
           (my-flatten (cdr ls))))))