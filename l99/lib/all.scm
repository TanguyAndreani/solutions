(define (my-last ls)
  (if (or (not (list? ls)) (null? ls))
      'undefined
      (if (null? (cdr ls))
          ls
          (my-last (cdr ls)))))

(define (my-but-last ls)
  (if (or (not (list? ls)) (null? ls) (null? (cdr ls)))
      'undefined
      (if (null? (cddr ls))
          ls
          (my-last (cdr ls)))))

(define (element-at ls n)
  (if (or (not (list? ls)) (null? ls))
      'undefined
      (if (zero? (- n 1))
          (car ls)
          (element-at (cdr ls) (- n 1)))))