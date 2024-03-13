;Determine the least common multiple of the numerical values of a nonlinear list.
(defun lcm (list)
  (let ((l (mapcar #'(lambda (x) (if (numberp x) x 1)) list)))
    (reduce #'lcm l)))