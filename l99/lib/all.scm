(define (my-last ls)
  (if (null? (cdr ls))
      ls
      (my-last (cdr ls))))

(define (my-but-last ls)
  (if (null? (cddr ls))
      ls
      (my-last (cdr ls))))

(define (element-at ls n)
  (if (zero? (- n 1))
      (car ls)
      (element-at (cdr ls) (- n 1))))

(define (my-length ls)
  (if (null? ls)
      0
      (+ 1 (my-length (cdr ls)))))
