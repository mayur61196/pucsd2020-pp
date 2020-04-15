import { Component, OnInit } from '@angular/core';
import { RestApiService } from "../shared/rest-api.service";

@Component({
  selector: 'app-user-search',
  templateUrl: './user-search.component.html',
  styleUrls: ['./user-search.component.css']
})
export class UserSearchComponent implements OnInit {
  User: any = [];
  constructor(public restApi: RestApiService) { }

  ngOnInit(): void {
  }


getUserById(id: string) {
  return this.restApi.getUser(id).subscribe((data: {}) => {

    console.log(data);
    this.User = data;



  })
}
loadUsers() {
  return this.restApi.getUsers().subscribe((data: {}) => {
    console.log(data);

    this.User = data;
  })
}
deleteUser(id) {
  if (window.confirm('Are you sure, you want to delete?')){
    this.restApi.deleteUser(id).subscribe(data => {
      this.loadUsers()
      //this.router.navigate(['/users-list'])
    })
  }
}  
}
